#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

class Graph {
private:
    // Adjacency list to store the graph
    std::unordered_map<int, std::list<int>> adjList;

    // Helper function for DFS
    void DFSUtil(int v, std::vector<bool>& visited) {
        // Mark the current node as visited
        visited[v] = true;
        std::cout << v << " ";

        // Recur for all vertices adjacent to this vertex
        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    // Function to add an edge between two vertices
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);  // Since the graph is undirected
    }

    // Function to perform DFS traversal starting from vertex 'start'
    void DFS(int start) {
        // Find the maximum vertex number
        int maxVertex = 0;
        for (const auto& pair : adjList) {
            maxVertex = std::max(maxVertex, pair.first);
        }

        // Keep track of visited vertices (size should be maxVertex + 1)
        std::vector<bool> visited(maxVertex + 1, false);

        // Call the recursive helper function to perform DFS
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g;

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform DFS starting from vertex 0
    std::cout << "DFS starting from vertex 0:" << std::endl;
    g.DFS(0);

    return 0;
}
