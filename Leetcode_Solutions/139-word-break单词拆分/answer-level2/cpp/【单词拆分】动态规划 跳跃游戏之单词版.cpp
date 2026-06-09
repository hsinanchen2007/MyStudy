### 执行时间
![图片.png](https://pic.leetcode-cn.com/d94bc4f2e4944ced3244bddab2526b88b1ea3398f03bf12489658b56ecf61c08-%E5%9B%BE%E7%89%87.png)

看个乐~~


### 思路
1. 动态规划
	> 整体思路有点像 [55.跳跃游戏](https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/)
2. 定义 `vector<bool> dp(s.size() + 1, false)` 
    * `dp[i]` 表示第 i 个字符前，所有的字符是否可以按字典拆分成单词
    * 其中第 i - 1 个字符是上一个词的结尾字母，第 i 个字符是一个新词的开头字母
    * 初始值 `dp[0] = true` ，表示第 0 个字符是一个新词的开头字母
    * 所求的答案为 `dp[s.size()]` ，表示这个字符串是否可以拆分成字典中的单词
3. 从前往后遍历字符串，我们只对新词的开头字母进行字典匹配，将每一个匹配成功的词后面的字母更新为新词开头字母
4. 设置一个变量记录所有最大的新词开头字母，如果当前字符已经超过了所有新词开头字母，可以剪枝返回 false 了

### 模拟
```
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
```
![图片.png](https://pic.leetcode-cn.com/2d8b15bc1cd5ae6dca962326640cd3ab3f4a850575184446375b2ca2157e56d9-%E5%9B%BE%E7%89%87.png)


### 答题
```C++
bool wordBreak(string s, vector<string>& wordDict)
{
    size_t validEnd = 0;
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i == validEnd + 1) return false;
        if (!dp[i]) continue;
        for (auto& word : wordDict)
        {
            size_t newEnd = i + word.size();
            if (newEnd > s.size()) continue;
            if (memcmp(&s[i], &word[0], word.size()) == 0)
            {
                dp[newEnd] = true;
                validEnd = max(validEnd, newEnd);
            }
        }
    }
    return dp.back();
}
```

### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)


