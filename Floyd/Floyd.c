#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 9999999

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g)
{
	int i, j;
	printf("\nStart Node : ");
	scanf_s("%d", &i);
	printf("End Node : ");
	scanf_s("%d", &j);



	if (A[i][j] == INF) {

		printf("Shortest Distance : * \n");
	}
	else {
		printf("Shortest Distance : %d\n", A[i-1][j-1]);
	}
	
}


void floyd(GraphType* g)
{

	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(g);
	}
}



int main(void)
{
	GraphType g = { 10,
	{{ 0, 3, INF, INF, INF, 11, 12, INF, INF, INF },
	{ 3,  0, 5, 4, 1, 7, 8, INF, INF, INF },
	{ INF, 5, 0, 2, INF, INF, 6, 5, INF, INF },
	{ INF, 4, 2, 0, 13, INF, INF, 14, INF, 16 },
	{ INF, 1, INF, 13, 0, 9, INF, INF, 18, 17 },
	{ 11, 7, INF, INF, 9, 0, INF, INF, INF, INF },
	{ 12, INF, 6, INF, INF, INF, 0, 13, INF, INF  },
	{ INF, INF, 5, 14, INF, INF, 13, 0, INF, 15  } ,
	{ INF, INF, INF, INF, 18, INF, INF, INF, 0, 10  },
	{ INF, INF, INF, 16, 17, INF, INF, 15, 10, 0  }}
	};

	printf("Floyd-Warshall Algorithm\n");
	floyd(&g);
	return 0;
}
