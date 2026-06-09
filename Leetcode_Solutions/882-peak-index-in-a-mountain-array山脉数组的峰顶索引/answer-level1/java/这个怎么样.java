```
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int mid = A.length / 2;
        while(A[mid] < A[mid - 1]){
            mid--;
        }
        while(A[mid] < A[mid + 1]){
            mid++;
        }
        return mid;
    }
}
```
