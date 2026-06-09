### 解题思路


### 代码

```java
class Solution {
    public int peakIndexInMountainArray(int[] a) {
        int start = 0;
        int end = a.length - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (a[mid] > a[mid - 1] && a[mid] < a[mid + 1]) {
                //上升区间
                start = mid;
            } else if (a[mid] < a[mid - 1] && a[mid] > a[mid + 1]) {
                //下降区间
                end = mid;
            } else {
                return mid;
            }
        }
        if (a[start] > a[start - 1] && a[start] > a[start + 1]) {
            return start;
        }
        if (a[end] > a[end - 1] && a[end] > a[end + 1]) {
            return end;
        }
        return -1;
    }
}
```