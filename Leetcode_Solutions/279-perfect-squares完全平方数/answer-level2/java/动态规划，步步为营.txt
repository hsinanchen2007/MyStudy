

```java
class Solution {
    public int numSquares(int n) {
        int res[] = new int[n+1];
        Arrays.fill(res, Integer.MAX_VALUE);
        res[1] = 1;
        for(int i=1; Math.pow(i, 2) <= n; i++){
            res[(int)Math.pow(i, 2)] = 1;
        }
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=i/2; j++){
                res[i] = Math.min(res[i], res[j] + res[i-j]);
            }
        }
        return res[n];
    }
}
```
