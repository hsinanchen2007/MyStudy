![image.png](https://pic.leetcode-cn.com/5de3c3514408947a9971bbdc3d9fda718459278e965f9f8a23dba3173708e7de-image.png)

```
class Solution {
    public int findIntegers(int num) {
        int[] dp;   //dp[i]是小于2^i的符合题意的个数
        int ans, k, t, i;   

        if(num == 0)
            return 1;
        if(num == 1)
            return 2;
        k = log2(num);  //k是num二进制的位数
        t = pow2(k);
        dp = new int[1+k];
        dp[0] = 1;
        dp[1] = 2;
        for(i = 2; i < k + 1; i++)
            dp[i] = dp[i-1] + dp[i-2];
        ans = dp[k];
        num %= t;
        t /= 2;
        k--;
        while(num > 0){
            if(num >= t)
                return ans + dp[k];
            while(num < t){
                t /= 2;
                k--;
            }
            ans += dp[k];
            num %= t;
            t /= 2;
            k--;
        }
        return ans + 1;   
    }

    private int log2(int n){
        int ans;

        ans = -1;
        while(n > 0){
            ans++;
            n /= 2;
        }
        return ans;
    }

    private int pow2(int n){
        int ans;

        ans = 1;
        while(n > 0){
            ans *= 2;
            n--;
        }
        return ans;
    }
}
```
递归解法超时(多次算二进制位数),上面是根据递归解法得来的
```
class Solution {
    public int findIntegers(int num) {
        int k, t;

        if(n == 0)
            return 1;
        if(n == 1)
            return 2;
        k = log2(n);
        t = pow2(k);
        return findIntegers(t - 1) + findIntegers(Math.min(t / 2 - 1, num % t));
    }

    private int log2(int n){
        int ans;

        ans = -1;
        while(n > 0){
            ans++;
            n /= 2;
        }
        return ans;
    }

    private int pow2(int n){
        int ans;

        ans = 1;
        while(n > 0){
            ans *= 2;
            n--;
        }
        return ans;
    }
}
```

