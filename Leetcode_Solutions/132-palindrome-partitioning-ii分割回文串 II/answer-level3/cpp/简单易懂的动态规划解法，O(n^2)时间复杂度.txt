### 解题思路
求最小分割次数，很明显可以采用动态规划求解。而动态规划实际是暴力搜索，只是在计算过程中保存了一些状态，减少了重复计算，使得总的计算复杂度降低。

### 首先看看暴力搜索可以怎么求解。
对于任意一个字符串，我们可以遍历所有的划分。以字符串 aabac 为例
只划分可以将其分为 
aaba,c
aab,ac
aa,bac
a,abac
最小划分次数 = 这四种划分后得到子串最小划分次数 + 1。

可以很明显发现a,aa,aab,aaba之间的关系：子问题与原问题
也可很明显发现c,ac,bac,abac之间的关系：子问题与原问题

如果继续划分，就是求其子问题的最小划分次数。

# 因此我们自低向上，先求子问题，再求原问题。
求解顺序也就是：a, aa, aab, aaba, aabac
假设已经知道 aabac 之前所有子问题的最小分割次数，那么求解 aabac为

```
f(aabac) = min(
          (aabac)本身是否是回文
          f(a) + f(abac) +1,
          f(aa) + f(bac) +1,
 		  f(aab) + f(ac) +1,
          f(aaba) + f(c) +1,
)

```

f(a) -- f(aaba)都已知，但是f(c) -- f(abac)却未知。
当我们去判断f(abac)最小划分次数时，发现这又是一个新的原问题。这条路好像走错了。

其实是我们没有理解清楚。因为f(c)-- f(abac)根本不需要再进行划分，而且只在不划分的情况下就是回文串时，才有效。

### 那么现在说最看起来最难的问题：为什么f(c) --  f(aaba)都可以不切分了。
###原因很简单，一讲就懂
假设将 aabac 分为了 a ， abac;如果再切分abac为 a, bac。
等价于将aabac 切分为 a,a,bac。这个问题怎么看着有点眼熟呀！
f(a)+f(a)+f(bac)+2 >= f(aa)+f(bac)+1 ;这不就是第二项嘛。
同理将abac 切分为 ab,ac等价于将aabac 切分为 a,ab,ac。
f(a)+f(ab)+f(ac)+2 >= f(aab)+f(ac)+1 ;这不就是第三项嘛。
其他的类似，总之f(c)-- f(abac)再次切分，一定是大于不切分的情况。而我们求最小切分次数，所以不需要再切分。

f(c) --  f(abac)不载划分。可得

 ```
f(aabac) = min(
          isReStr(aabac)？ 0：max_value 
          isReStr(abac)？ f(a) + 1: max_value 
          isReStr(bac)？ f(aa) + 1: max_value 
 		  isReStr(ac)？ f(aab) + 1: max_value 
          isReStr(c)？ f(aaba) + 1: max_value 
)
//函数isReStr(s) 为判断s是否是回文
```

其中isReStr(c)一定是True,所以f(aabac) 肯定小于 f(aaba) + 1。
由于f(a) -- f(aaba)已知，那么我们就可以得到f(aabac)，最后的答案也就有了。

### 如何高效的判断字符是否是回文串
遍历判断字符是否是回文是非常慢的方法。其实判断是否是回文串也是一个动态规划问题。
如果知道了所有子串是否是回文串，只需要一步就可以判断出是否是回文串。
二维数组isReStr[j][i] 表示s[j]开头s[i]结尾的字符是否是回文串。
状态转移方程：
若：s[j] == s[i] && (i-j < 3 || isReStr[j+1][i-1])
isReStr[j][i] = ture;
else
isReStr[i][j] = false;
也就是开头和结尾必须相等的情况下，长度小于3或者s[j=1][i-1]是回文串。则是回文串。

### 最小切分次数的动态规划要点
状态： dp[i] 表示s[0]开头s[i]结尾字符串最小切分次数，使得所有的子串都是回文。
状态转移方程：

 ```
dp[i] = min(
          isReStr(s[0 - i])？ 0
          isReStr(s[1 - i])？ dp[0] + 1
		   ...
          isReStr(s[(i) - i])？ dp[i-1] + 1
)
//函数isReStr(s) 为判断s是否是回文
```


### 代码

```cpp
class Solution {
public:
	int minCut(string s) {
		if (s.size() < 2)
			return 0;
		int len = s.size();
        std::vector<int> dp(len);// 存储最小切分次数
		//存储是否是回文串
		std::vector<std::vector<bool>> isReStr(len, std::vector<bool>(len,false)); 
		for (int i = 0; i < len; i++)
		{
            dp[i] = i;//s[0]-s[i] 最多切分i次，子串都成为回文
			for (int j = 0; j <= i; j++)
			{
				if (s[j] == s[i] && (i-j <= 2 || isReStr[j+1][i-1]) )//s[j]--s[i]是不是回文串
				{
                    isReStr[j][i] = true; //s[j]-s[i] 不切分就是回文串
                    if(j == 0)
                        dp[i] = 0;//s[0]-s[i] 是回文串
                    else
                        dp[i] = std::min(dp[i], dp[j-1] + 1);
				}
			}
		}
		return dp[len-1];
	}
};
```