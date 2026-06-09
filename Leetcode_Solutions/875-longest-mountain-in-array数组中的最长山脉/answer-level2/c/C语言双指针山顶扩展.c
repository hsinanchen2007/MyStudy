遍历数组元素，当前元素大于左边且小于右边时（即山顶时）向两边扩展，求左右指针之差;
![Screenshot from 2020-03-31 21-53-09.png](https://pic.leetcode-cn.com/fa2052ed38d9b07c06228ede008e264d3a342c561d7fc22554a2df59a73741ed-Screenshot%20from%202020-03-31%2021-53-09.png)



```c
int Max(int a, int b) { return a > b ? a : b; }
int longestMountain(int *A, int ASize)
{
    int i, l, r, max = 0;
    for (i = 1; i < ASize - 1; i++)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            for (l = i; l - 1 >= 0 && A[l - 1] < A[l]; l--);
            for (r = i; r + 1 < ASize && A[r] > A[r + 1]; r++);
            max = Max(r - l + 1, max);
        }
    }
    return max;
}
```