### 解题思路
递归：
首先：将数组一分为二，将index为偶数的放到左边数组，index为奇数的书放到右边数组。
分别对左右数组递归执行
最后，将左右数组copy回原数组

参考官方题解，如果没有“左边为奇数，右边为偶数，即可以是漂亮数组” 的提示，此题不好做

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void proc(int *arr, int n)
{
    if (n == 1)
        return;

    int i;
    int odd_len = (n + 1) / 2;
    int even_len = n / 2;
    int arr_odd[odd_len];
    int arr_even[even_len];

    for (i = 0; i < odd_len; i++)
        arr_odd[i] = arr[2 * i];
    for (i = 0; i < even_len; i++)
        arr_even[i] = arr[2 * i + 1];

    proc(arr_odd, odd_len);
    proc(arr_even, even_len);

    for (i = 0; i < odd_len; i++)
        arr[i] = arr_odd[i];
    for (i = odd_len; i < n; i++)
        arr[i] = arr_even[i - odd_len];

}

int* beautifulArray(int N, int* returnSize)
{
    if (!returnSize)
        return NULL;

    int *arr = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    proc(arr, N);

    *returnSize = N;
    return arr;
}
```