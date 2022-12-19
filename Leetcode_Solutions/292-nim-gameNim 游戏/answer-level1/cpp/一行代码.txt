一开始想到的是动态规划， dp[i] 表示当石头个数是i的时候, 赢还是输， dp[1] = true, dp[2] = true,  dp[3] = true; 
从i = 4 开始 如果 dp[i-1], dp[i-2], dp[i-3] 全都是 true的话， 那么 dp[i] = false, 否则 dp[i] = true, 一开始开了 n大小的dp数组，后来一想
只要保存i-1,i-2,i-3就行， 优化了一下，但是还是超时.
 后来发现 就是 true ,true , true , false , true, true , true , false ,... , 每4个一个循环， 所以只要判断一下是不是4的倍数就好了.

```
if(n % 4 == 0) return false;
else return true;
```


