### 解题思路
1.递归+记忆化搜索
2.递归其实就是穷举，但是这道题不太好想出来穷举的方式。

参考与链接（侵删）：[https://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/](https://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/)
![image.png](https://pic.leetcode-cn.com/d020b9adb96cd3de5d2d32ad55e2f01e39fad40f71c9e9bc2db16aa3861c2639-image.png)


### 代码

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> inDict(wordDict.begin(), wordDict.end());
        return wordBreaks(s, inDict);
    }
private:
    bool wordBreaks(string const& s, unordered_set<string>& inDict){
        if(mem.count(s)){
            return mem[s];
        }
        bool ret = false;
        if(s.empty())
            return true;
        for(int i = 0; i < s.size(); i++){
            ret |=  (wordBreaks(s.substr(0,i), inDict) && inDict.count(s.substr(i, s.size()-i)));
        }
        mem[s] = ret;
        return mem[s];
    }
    unordered_map<string, bool> mem;
};
```

### 解题思路
1.动态规划
2.状态表达式和转移方程比上面递归好想一些
3.求解状态表达式同样的不是常亮时间，与状态表达式的规模成正比。
### 代码

```cpp
class Solution {
public:
    //dp[i]: 表示s的前i个字符组成的子串是否可以拆解分成字典中的单词
    //dp[i] = dp[i-1] && dict(s.substr(i-1,1)) || dp[i-2] && dict(s.substr(i-2,2)) || dp[i-3] && dict(s.substr(i-3,3))
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> inDict(wordDict.begin(), wordDict.end());
        bool dp[s.size() + 1] = {0};
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                //dp[i] |=  dp[j] && inDict.count(s.substr(j, i - j));
                //不用遍历完所有子问题，有个满足就可以退出了
                if(dp[j] && inDict.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
```

### 解题思路
宽度有限搜索？

### 代码

```cpp

```
