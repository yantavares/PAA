#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    string s;
    getline(cin, s);
    vector<int> arr;
    int num = 0;
    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else if (c == ' ')
        {
            arr.push_back(num);
            num = 0;
        }
    }
    arr.push_back(num);
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
