#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int S, const vector<int> &sizes, const vector<int> &values)
{
    int N = sizes.size();
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            if (sizes[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - sizes[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][S];
}

int main()
{
    int S, N;
    cin >> S >> N;

    vector<int> sizes(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++)
    {
        cin >> sizes[i] >> values[i];
    }

    int maxTotalValue = knapsack(S, sizes, values);
    cout << maxTotalValue << endl;

    return 0;
}