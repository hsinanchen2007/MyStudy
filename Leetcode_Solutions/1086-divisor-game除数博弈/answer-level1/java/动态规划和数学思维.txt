# 数学思想
规则：Alice先手
观察：谁先从2的基础减去1谁胜

1.若N为奇数，则可以整除的为奇数。若可以整除，Alice先手减去奇数，得到偶数，则Bob只需每次减一直到2，Bob胜；Alice为奇数不能整除，则需每次减1，Bob先得到2，Bob胜。所以奇数的话Alice输。
2.若N为偶数，则其可以整除的为奇数或偶数。为保证胜利，Alice只需每次减一先得到2即可。如果Alice减去1得到奇数，由规则 1 可知，奇数的话先手会输（此时Bob先手）。所以偶数的话Alice会赢。

### 代码

```java
class Solution {
    public boolean divisorGame(int N) {
        return N % 2 == 0;
    }
}
```
# 动态规划
dp[]代表一个长度为n+1的数组，如果 dp[n-x]为false,则Alice会减去x,即 Bob==dp[n-x]==false, Alice胜。否则Alice输，因为不管x是多少，dp[n-x]为true, 则dp[n]==Alice==false.
```java
public boolean divisorGame(int N) {

        if(N == 1) return false;
        if(N == 2) return true;

        boolean[] dp = new boolean[N+1];
        dp[1] = false;
        dp[2] = true;

        for(int i = 3; i<=N; i++){
            dp[i] = false;
            for(int j = 1; j<i; j++){
                if(i % j == 0 && !dp[i - j]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
```
