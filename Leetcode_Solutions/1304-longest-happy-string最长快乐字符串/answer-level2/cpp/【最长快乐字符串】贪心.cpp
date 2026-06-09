### 思路
1. 需要对字母和其个数连带排序
    11. 使用 `vector<vector<int>>` ，将字母 a 转化为 `int` ，放在第 2 维
    12. 这样对其排序，会优先根据第 1 维的数量来排序
2. 制作规则
    21. 当数量最多的字母，比其他两个字母的数量之和还多，每次填充 2 个最多字母，配 1 个第二多字母
    22. 否则，就尽量 2 个最多字母配 2 个第二多字母
    23. 当最多字母不足 2 个（无需搭配），或者第二多字母不足 1 个（无法搭配），跳出循环进行最后一次填充
    24. 最后一次填充按照顺序每个字母最多填 2 个

### 答题
```C++ []
    string longestDiverseString(int a, int b, int c)
    {
        string ans;
        vector<vector<int>> cnt = { {a, 0}, {b, 1}, {c, 2} };

        while (true)
        {
            sort(cnt.rbegin(), cnt.rend());
            if (cnt[0][0] < 2) break;
            if (cnt[1][0] < 1) break;

            ans += ('a' + cnt[0][1]);
            ans += ('a' + cnt[0][1]);
            if (cnt[0][0] <= cnt[1][0] + cnt[2][0] && cnt[1][0] > 1)
            {
                ans += ('a' + cnt[1][1]);
                cnt[1][0] -= 1;
            }
            ans += ('a' + cnt[1][1]);
            cnt[1][0] -= 1;
            cnt[0][0] -= 2;
        }

        sort(cnt.rbegin(), cnt.rend());
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i][0] == 0) return ans;
            ans += ('a' + cnt[i][1]);
            if (cnt[i][0] != 1)
            {
                ans += ('a' + cnt[i][1]);
            }
        }
        return ans;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

