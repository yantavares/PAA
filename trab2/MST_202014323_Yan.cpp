#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<long long, long long> pii;
typedef vector<vector<pii>> Graph;

// Usando prim algorithm para encontrar o MST

long long primMST(const Graph &graph, long long startNode)
{
    long long numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    long long mstWeight = 0;

    pq.push(make_pair(0, startNode));

    while (!pq.empty())
    {
        long long u = pq.top().second;
        long long weight = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        mstWeight += weight;

        for (const auto &neighbor : graph[u])
        {
            long long v = neighbor.first;
            long long edgeWeight = neighbor.second;

            if (!visited[v])
                pq.push(make_pair(edgeWeight, v));
        }
    }

    return mstWeight;
}

int main()
{
    long long N, M;
    cin >> N >> M;

    Graph graph(N);

    for (long long i = 0; i < M; i++)
    {
        long long u, v, weight;
        cin >> u >> v >> weight;
        graph[u - 1].push_back(make_pair(v - 1, weight));
        graph[v - 1].push_back(make_pair(u - 1, weight));
    }

    long long mstWeight = primMST(graph, 0);
    cout << mstWeight << endl;

    return 0;
}
