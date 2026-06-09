```
public int maxJumps(int[] arr, int d) {
        int len = arr.length;
        
        Integer[] index = new Integer[len];
        for(int i = 0; i < len; i++) {
            index[i] = i;
        }
        
        Arrays.sort(index, (a, b) -> (arr[a] - arr[b]));
        
        int[] dp = new int[len];
        Arrays.fill(dp, 1);
        
        for(int i = 0; i < len; i++) {
            int idx = index[i];
            for(int j = 1; j <= d; j++) {
                int idx2 = idx + j;
                if (idx2 >= len || arr[idx2] >= arr[idx]) {
                    break;
                }
                dp[idx] = Math.max(dp[idx], dp[idx2] + 1);
            }
            
            for(int j = 1; j <= d; j++) {
                int idx2 = idx - j;
                if (idx2 < 0 || arr[idx2] >= arr[idx]) {
                    break;
                }
                dp[idx] = Math.max(dp[idx], dp[idx2] + 1);
            }
        }
        
        int res = 1;
        for(int a : dp) {
            if (a > res) {
                res = a;
            }
        }
        
        return res;
    }
```
