```java
class Solution {
    public int findMinMoves(int[] machines) {
        int sum  = 0;
        int n = machines.length;
        for (int m : machines) {
            sum += m;
        }
        if (sum % n != 0) return -1;
        int avg = sum / n;
        int res = 0;
        int cnt = 0;
        for (int m : machines) {
            cnt += m - avg;
            res = Math.max(Math.max(res, Math.abs(cnt)), m - avg);
        }
        return res;
    }
}
```