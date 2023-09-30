#include <iostream>
using namespace std;
int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[lb], a[end]);
    return end;
}

void quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int p = partition(a, lb, ub);
        quick_sort(a, lb, p - 1);
        quick_sort(a, p + 1, ub);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {15, 34, 12, 18, 40};
    int n = 5;
    cout << "Before swap" << endl;
    print(a, n);
    quick_sort(a, 0, n - 1);
    cout << "After swap" << endl;
    print(a, n);
    return 0;
}