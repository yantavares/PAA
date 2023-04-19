#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &arr, int size, int target)
{
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    if (arr[lb] == target)
    {
        return lb;
    }

    return -1;
}

int main()
{
    int s, n, el;

    vector<int> v;

    scanf("%d %d", &s, &n);

    for (int i = 0; i < s; i++)
    {
        scanf("%d", &el);
        v.push_back(el);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &el);
        printf("%d\n", binarySearch(v, s, el));
    }

    return 0;
}
