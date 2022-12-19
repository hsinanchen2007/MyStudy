```java
class Solution {
    public int findJudge(int n, int[][] trust) {
        boolean[] isJudge = new boolean[n+1];
        int[] trustedNum = new int[n + 1];
        Arrays.fill(isJudge, true);

        for (int[] tu : trust) {
            isJudge[tu[0]] = false;
            trustedNum[tu[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (isJudge[i] && trustedNum[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}
```
