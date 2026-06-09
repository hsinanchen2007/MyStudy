corner case 蛮多的

```
class Solution {
    public int videoStitching(int[][] clips, int T) {
        // corner case
        if (T == 0) return 0;
        int[] dp = new int[T+1];
        Arrays.sort(clips, (arr1, arr2) -> compare(arr1, arr2));
        Arrays.fill(dp, 1000000);
        dp[0] = 0;
        // corner case
         if (clips[0][0] != 0) return -1;
        for (int i = 0; i < clips.length; i++) {
            int min = clips[i][0];
            int max = clips[i][1];
            // corner case
            if (min > T) break;
            if (dp[min] > 100) return -1;

            for (int j = min + 1; j <= max; j++) {
                // corner case
                if (j > T) break;
                dp[j] = Math.min(dp[j], dp[min] + 1);
            }
        }

        return dp[T] > 100 ? -1: dp[T];
    }

    int compare(int[] arr1, int[] arr2) {
        if (arr1[0] != arr2[0]) {
            return arr1[0] - arr2[0];
        }
        return arr1[1] - arr2[1];
    }
}
```
