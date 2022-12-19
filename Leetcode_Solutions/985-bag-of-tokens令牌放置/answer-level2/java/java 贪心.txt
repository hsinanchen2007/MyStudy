贪心策略：先排序，我们可以用前面的令牌换后面的令牌来得到更多的能量。但是这样每次就少了两个令牌，我们不知道什么时候停止涨能量有最大值。那么每次都扫一遍就好了。

```java
class Solution {
    public int bagOfTokensScore(int[] tokens, int P) {
        int res = 0;
        int n = tokens.length;
        Arrays.sort(tokens);
        
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int tmp = P, cnt = 0;
            for (int i = l; i <= r; i ++)
            {
                if (tmp < tokens[i]) break;
                tmp -= tokens[i];
                cnt ++;
            }
            if (cnt == 0) return res;
            res = Math.max(res, cnt);
            P += tokens[r --] - tokens[l ++];
        }
        return res;
    }
}
```