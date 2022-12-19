# 0.主要思想
我们知道如果一个字符`s[i]`前有和它一样的字符`s[j]`，那么以`s[j]`结尾的最长的字串长度就是`i-j`，这样只需要两层循环就可以完成了

# 1.存在的问题

如果在`s[i:j+1]`之间有重复的怎么办？我在这边用一个数组`dp`存储以每一个字符结尾的最长字串的长度，那么**以`s[i]`结尾的最长字串的长度最多只有`dp[i-1]+1`的长度，**从`i-1`往前遍历即可。在i的遍历时顺便把最大值求出来即可。

# 2. 执行效率
![leetcode0003.png](https://pic.leetcode-cn.com/e42920af096bb4a531d589436ed408070aabeefce38b1a4fe8a953dc2cea481e-leetcode0003.png)

# 3.代码实现
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;
        int dp[len] ={1};
        int ans = 1;
        for (int i = 1;i<len;i++){
            for (int j = i-1;j>=i-1-dp[i-1];j--)
            {
                if (j == i-1-dp[i-1]) {
                    dp[i] = dp[i-1]+1;
                    break;
                }
                if (s[i] == s[j]){
                    dp[i]=i-j;
                    break;
                }
            }
            if (dp[i]>ans) ans = dp[i];
        }
        return ans;
    }
};
```
