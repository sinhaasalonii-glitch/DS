#include <stdio.h>

#define MAX_NODES 100

// Define the graph structure
struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
};

// Function to initialize the graph
void initGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;

    // Initialize adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge
void addEdge(struct Graph *graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
    graph->adjacencyMatrix[destination][source] = 1;
}

// Function to print the adjacency matrix
void printGraph(struct Graph *graph) {
    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Graph graph;
    int numVertices, numEdges, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize the graph
    initGraph(&graph, numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Add edges to the graph
    for (int i = 0; i < numEdges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &source, &destination);

        addEdge(&graph, source, destination);
    }

    // Print the adjacency matrix
    printGraph(&graph);

    return 0;
}