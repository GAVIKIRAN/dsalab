#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge
{
    int u, v, weight;
};

struct Edge edges[MAX];
int parent[MAX];

int n, e;

/* Find the parent */
int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

/* Join two sets */
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);

    parent[rootV] = rootU;
}

/* Sort edges by weight */
int compare(const void *a, const void *b)
{
    struct Edge *x = (struct Edge *)a;
    struct Edge *y = (struct Edge *)b;

    return x->weight - y->weight;
}

/* Kruskal's Algorithm */
void kruskal()
{
    int i;
    int count = 0;
    int totalCost = 0;

    /* Initialize parent */
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    /* Sort edges */
    qsort(edges, e, sizeof(struct Edge), compare);

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        /* Check for cycle */
        if (find(u) != find(v))
        {
            printf("%d -- %d = %d\n",
                   u, v, edges[i].weight);

            totalCost = totalCost + edges[i].weight;

            count++;

            unionSet(u, v);
        }
    }

    printf("Total cost of MST = %d\n", totalCost);
}

int main()
{
    int i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);
    }

    kruskal();

    return 0;
}