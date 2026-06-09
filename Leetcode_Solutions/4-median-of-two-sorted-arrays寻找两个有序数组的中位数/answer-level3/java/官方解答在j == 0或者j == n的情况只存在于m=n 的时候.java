### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] arrA, int[] arrB) {
        int m = arrA.length, n = arrB.length;
        if (m > n) {
            int[] tmpArr = arrA;
            arrA = arrB;
            arrB = tmpArr;

            int tmpLen = m;
            m = n;
            n = tmpLen;
        }
        int min = 0, max = m, halfLen = (m + n + 1) / 2;
        while (min <= max) {
            int i = (min + max) / 2;
            int j = halfLen - i;
            if (i < max && arrB[j - 1] > arrA[i]) {
                min = i + 1;
            } else if (i > min && arrA[i - 1] > arrB[j]) {
                max = i - 1;
            } else {
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = arrB[j - 1];
                } else if (j == 0) {
                    maxLeft = arrA[i - 1];
                } else {
                    maxLeft = Math.max(arrB[j - 1], arrA[i - 1]);
                }

                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) {
                    minRight = arrB[j];
                } else if (j == n) {
                    minRight = arrA[i];
                } else {
                    minRight = Math.min(arrB[j], arrA[i]);
                }
                
                return (maxLeft + minRight) / 2.0;
            }
        }

        return 0.0;
    }
}
```

官方解答在j == 0或者j == n的情况只存在于m=n 的时候，
其他情况下，j必然>0并且<n