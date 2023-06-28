#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int minimumOperations(const string& A, const string& B) {
    int m = A.length();
    int n = B.length();
 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
 
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
 
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;
 
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] });
        }
    }
 
    return dp[m][n];
}
 
int main() {
    int T;
    cin >> T;
 
    for (int t = 0; t < T; t++) {
        string A, B;
        cin >> A >> B;
 
        int minOps = minimumOperations(A, B);
        cout << minOps << endl;
    }
 
    return 0;
}