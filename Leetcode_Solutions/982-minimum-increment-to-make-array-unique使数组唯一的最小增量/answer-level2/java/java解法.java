执行用时 :43 ms, 击败了49.67%的用户.
内存消耗 :49.2 MB, 击败了91.43%的用户.
```
class Solution {
    public int minIncrementForUnique(int[] A) {
        Arrays.sort(A);
        int count = 0;
        for(int i = 1; i< A.length; i++){
            if(A[i]<=A[i-1]){
                count += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return count;
    }
}
```