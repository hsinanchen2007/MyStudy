这道题思路与交换数字构造比当前排列要大的最小排列相同。
1.从后往前找到第一个逆序对，下标`i`指向逆序对的较大值，若`i`为-1说明整个序列为递增序列，不存在较小排列；
2.下标`i`到序列长度为下标的开区间为递增序列，用二分搜索，下标`lo`指向的是小于`A[i]`区间的右端点；
3.此题限制交换一次，为使当前序列更大需要向前寻找与`A[lo]`值相同的区间的左端点，与`A[i]`交换；若此题不限制交换次数，则直接交换`lo`和`i`，再将后面的递增序列翻转过来。

```
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int n = A.length, i;
        if (n <= 1) return A;
        
        for (i = n - 2; i >= 0; i--)
            if (A[i] > A[i + 1])
                break;
        
        if (i == -1) return A;
        
        int lo = i, hi = n - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if (A[mid] < A[i]) lo = mid;
            else hi = mid - 1;
        }
        
        while (A[lo - 1] == A[lo])
            lo--;
        
        int tmp = A[lo];
        A[lo] = A[i];
        A[i] = tmp;
        
//         for (int j = 0; j < (n - i - 1) / 2; j++) {
//             tmp = A[i + j + 1];
//             A[i + j + 1] = A[n - j - 1];
//             A[n - j - 1] = tmp;
//         }
        
        return A;
    }
}
```
