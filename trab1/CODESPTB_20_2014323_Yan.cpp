#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int temp[100000];

long int merge(int a[], int left, int mid, int right)
{

    long int count = 0;

    int i = left, j = mid, k = left;

    while (i < mid && j <= right)
    {

        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
            count += mid - i;
        }
    }
    while (i < mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= right)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    while (left <= right)
    {
        a[left] = temp[left];
        left++;
    }

    return count;
}

long int mergeInsertionSwap(int a[], int left, int right)
{

    long int count = 0;
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        count += mergeInsertionSwap(a, left, mid);

        count += mergeInsertionSwap(a, mid + 1, right);

        count += merge(a, left, mid + 1, right);
    }
    return count;
}

int main()
{
    int count;

    cin >> count;

    for (size_t i = 0; i < count; i++)
    {
        int k, num;

        cin >> k;

        int arr[k];

        for (size_t l = 0; l < k; l++)
        {
            cin >> num;
            arr[l] = num;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        cout << mergeInsertionSwap(arr, 0, n - 1) << endl;
    }
    return 0;
}
