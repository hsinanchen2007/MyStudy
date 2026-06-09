### 思路
1. 构成回文串的特点是， 1 个字母可以构成回文串，2 个相同的字母可以构成回文串
2. 所以只要想一下单个（奇数个）字母怎么处理
3. 对字母计数
4. 判断奇数个字母的数量

### 答题
```C++ []
    bool canConstruct(string s, int k) 
    {
        if (s.size() < k) return false;
        vector<int> cnt(26, 0);
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }

        int odd = 0;
        for (auto x : cnt)
        {
            odd += (x % 2 == 1);
        }

        return odd <= k;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

