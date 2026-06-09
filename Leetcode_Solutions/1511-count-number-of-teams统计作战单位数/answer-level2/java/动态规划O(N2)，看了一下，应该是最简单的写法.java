```
public int numTeams(int[] rating) {
        int n = rating.length;
        int res = 0;
        
        int[] dp1 = new int[n];
        int[] dp2 = new int[n];
        Arrays.fill(dp1, 1);
        Arrays.fill(dp2, 1);
        
        for(int i = 1; i < n; i++) {
            int a = 1;
            int b = 1;
            for(int j = 0; j < i; j++) {
                if (rating[i] > rating[j]) {
                    a++;
                    res += (dp1[j] - 1);
                } else {
                    b++;
                    res += (dp2[j] - 1);
                }
            }
            
            dp1[i] = a;
            dp2[i] = b;
        }
        
        return res;
    }
```
