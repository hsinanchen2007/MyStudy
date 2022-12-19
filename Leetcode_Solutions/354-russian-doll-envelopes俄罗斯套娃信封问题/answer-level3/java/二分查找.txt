```java
class Solution {
    private int compare(int[] a1, int[] a2) {
        if (a1[0] == a2[0]) {
            return a2[1] - a1[1];
        } else {
            return a1[0] - a2[0];
        }
    }

    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes.length == 0) return 0;
        Arrays.sort(envelopes, this::compare);

        int result = 0;
        int[] dp = new int[envelopes.length+1];

        for (int[] envelop: envelopes) {
            int index = Arrays.binarySearch(dp, 0, result + 1, envelop[1]);
            if (index > 0) {
                continue;
            }
            index = -(index + 1);
            if (index == result + 1) {
                dp[++result] = envelop[1];
            } else if (dp[index] != envelop[1]) {
                dp[index] = Math.min(dp[index], envelop[1]);
            }
        }

        return result;
    }
}
```