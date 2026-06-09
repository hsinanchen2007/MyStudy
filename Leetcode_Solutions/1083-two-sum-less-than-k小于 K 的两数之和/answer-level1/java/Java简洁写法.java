```
class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        if (A == null || A.length < 2) return -1;
        int len = A.length;
        int l = 0;
        int r = len -1;
        Arrays.sort(A);
        int result = -1;
        while (l < r) {
            int sum = A[l] + A[r];
            if (sum < K) {
                l++;
                result = sum > result ? sum : result;
            } else r--;
        }
        return result;
    }
}
```
