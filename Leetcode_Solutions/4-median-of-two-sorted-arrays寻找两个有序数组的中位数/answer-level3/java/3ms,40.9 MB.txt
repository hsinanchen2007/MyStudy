### 解题思路
两个数组都是有序的，将两个数组看成一个数组
中位数的位置可知：(A.length + B.length) / 2
需要一个变量记录中位数的值
遍历两个数组，每次取两个数组中最小的值，并将对应数组下标+1
直到遍历次数达到中位数，此时中位数确定
考虑两个数组长度之和为偶数，需要再取中位数之后的最小数，下标确认了，很容易
返回

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int a = 0, b = 0;
        int len = (A.length + B.length) / 2 + (A.length + B.length) % 2;
        boolean isOdd = (A.length + B.length) % 2 == 1;
        int i = 0, j = 0;
        boolean lastAtA = false;
        while (i + j < len && (i < A.length || j < B.length)) {
            int tmpA = i < A.length ? A[i] : Integer.MAX_VALUE;
            int tmpB = j < B.length ? B[j] : Integer.MAX_VALUE;
            if (tmpA > tmpB) {
                a = tmpB;
                j++;
                lastAtA = false;
            } else {
                a = tmpA;
                i++;
                lastAtA = true;
            }
        }
        if (!isOdd) {
            int tmpA = i < A.length ? A[i] : Integer.MAX_VALUE;
            int tmpB = j < B.length ? B[j] : Integer.MAX_VALUE;
            b = tmpB > tmpA ? tmpA : tmpB;
        } else {
            b = a;
        }
        return ((double) (a + b)) / 2;
    }
}
```