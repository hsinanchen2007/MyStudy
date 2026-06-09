```
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int n = A.length;
        int first = 0, sec = 0, cur = 0, firSum = 0, secSum = 0, res = 0;
        while(cur < n){
            firSum += A[cur];
            secSum += A[cur];
            while(firSum > S){
                firSum -= A[first++];
            }
            while(sec <= cur && secSum >= S){
                secSum -= A[sec++];
            }
            res += sec - first;
            cur++;
        }
        return res;
    }
}
```