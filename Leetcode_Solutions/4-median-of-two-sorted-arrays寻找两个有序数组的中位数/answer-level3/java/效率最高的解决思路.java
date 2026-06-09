### 解题思路
两个有序数组的中位数，正常来说需要merge两个数组，然后找到中位数。
换一个思路， 我们把两个数组分别拆分成两部分。 A1,A2 和 B1,B2 使得的  
A1 B1 的元素数量和 等于 B1,B2（元素总数为偶数时）
或 A1 B1 的元素数量和 比 B1,B2 多一个（元素总数为奇数时）。
设 A2的第一个元素下标是i， B2的第一个元素下标是j， 则 i + j = (m + n + 1) / 2。
原本应该是 (m + n) / 2 我们再添加一个1，兼容了奇偶两种情况（仔细想想就明白了）。

现在要紧紧抓住i 和 j的固定关系，这将大大提高我们的效率。
通过在较短的数组中，二分查找i，最终确定i j的位置，并找到中位数。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        // 19:30~19:59
        int m = A.length;
        int n = B.length;
        if (m > n) {
            return findMedianSortedArrays(B, A);
        }

        // mStart  mEnd 的实际意义是分割线编号， m个元素，需要 0～m，共m+1个分割线
        int mStart = 0;
        int mEnd = m;
        int i = 0;
        int j = 0;

        while (mStart <= mEnd) { // 这里start和end重合后，仍需要再次进入 while循环，以便做最终的处理
            i = (mStart + mEnd) / 2;
            j = (m + n + 1) / 2 - i;
            if (i != 0 && j != n && A[i-1] > B[j]) {
                mEnd = i - 1;
            } else if (j != 0 && i !=m && B[j-1] > A[i]) {
                mStart = i + 1;
            } else {
                int midLeft = 0;
                if (i == 0) {
                    midLeft = B[j-1];
                } else if (j == 0) {
                    midLeft = A[i-1];
                } else {
                    midLeft = Math.max(A[i-1], B[j-1]);
                }

                if ((m + n) % 2 == 1) {
                    return midLeft;
                } 
                
                int midRight = 0;
                if (i == m) {
                    midRight = B[j];
                } else if (j == n) {
                    midRight = A[i];
                } else {
                    midRight = Math.min(A[i], B[j]);
                }
                return (midLeft + midRight) / 2.0;
            }
        }
        return 0.0;
    }
}
```