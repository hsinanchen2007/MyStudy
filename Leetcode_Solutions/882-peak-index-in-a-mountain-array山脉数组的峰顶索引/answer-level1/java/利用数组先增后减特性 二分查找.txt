```
   /**
     * 利用该数组先增后减的特性，二分查找
     * 数组左部分满足 A[mid] < A[mid + 1]  右部分不满足。
     * 当A[mid] < A[mid + 1]时， mid肯定不是最大值索引，在右半区查找
     */
    public int peakIndexInMountainArray(int[] A) {
        int left = 0, right = A.length, mid;
        while (left < right) {
            mid = (left + right) >>> 1;
            if (A[mid] < A[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
```
