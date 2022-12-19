```
class Solution {
    public int fixedPoint(int[] A) {
        // logn
        int start = 0;
        int end = A.length - 1;
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(A[mid] > mid) {
                end = mid - 1;
            }
            else if(A[mid] < mid){
                start = mid + 1;
            }
            else {
                while(mid >= 0 && A[mid] == mid)
                    mid --;
                return mid + 1;
            }
        }

        return A[start] == start? start : -1;
    }
}
```
