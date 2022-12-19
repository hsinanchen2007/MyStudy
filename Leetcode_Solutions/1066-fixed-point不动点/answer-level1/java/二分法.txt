### 解题思路
二分查找，要注意的是因为有可能有多个解，要找到其中最小的那个解就需要一直遍历到最小的mid为止

### 代码

```java
class Solution {
    public int fixedPoint(int[] A) {
        int len = A.length;
        int left = 0, right = len - 1;
        int res = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == mid) {
                res = res == -1 ? mid : Math.min(mid, res);
                right = mid - 1;
            } else if (A[mid] < mid) left = mid + 1;
            else right = mid - 1;
        } 
        return res;
    }
}


```