```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int low = 0, high = A.length;
        while(low < high) {
            int mid = (low + high) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (A[mid] < A[mid - 1]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return -1;
    }
}
```
