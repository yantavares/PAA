#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

// Usando prim algorithm para encontrar o MST

int primMST(const Graph &graph, int startNode)
{
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int mstWeight = 0;

    pq.push(make_pair(0, startNode));

    while (!pq.empty())
    {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        mstWeight += weight;

        for (const auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int edgeWeight = neighbor.second;

            if (!visited[v])
                pq.push(make_pair(edgeWeight, v));
        }
    }

    return mstWeight;
}

int main()
{
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1].push_back(make_pair(v - 1, weight));
        graph[v - 1].push_back(make_pair(u - 1, weight));
    }

    int mstWeight = primMST(graph, 0);
    cout << mstWeight << endl;

    return 0;
}
