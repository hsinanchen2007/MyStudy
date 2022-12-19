### 思路
1. 去掉前面的 0 
2. 去掉后面的 0 ，记录操作数
3. 如果此时长度只有 1 ，那么就返回操作数
4. 现在得到一个结尾是 1 的长度大于 1 的字符串，例：`1101`
    41. 因为结尾是 1 要进行 +1 操作，如： `01` -> `10` ， `01111` -> `10000`
    42. 把连续的 1 ，一口气全部变成 0 ，操作数等于变成 0 的个数加上最前面一个变成 1 的操作
    43. 需要在字符串头部插入一个 0 ，因为原头部的 1 肯定会被后面 +1
    44. 这一系列操作就可以放入一个循环处理

### 答题
```C++ []
    int numSteps(string s) 
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') continue;
            s = s.substr(i, s.size() - i);
            break;
        }
        while (s.back() == '0')
        {
            ans++;
            s.pop_back();
        }
        if (s.size() == 1) return ans;

        s.insert(s.begin(), '0');
        for (int i = s.size() - 1; i > 0;)
        {
            int cnt = 1;
            while (i - cnt >= 0 && s[i - cnt] == '1')
            {
                cnt++;
            }
            ans += cnt + 1;
            i -= cnt;
        }
        return ans;
    }
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

**如果感觉还不错就点个赞吧~**

这是 [我的leetcode](https://github.com/AhJo53589/leetcode-cn) ，帮助我收集整理题目，可以方便的 `visual studio` 调试，欢迎关注，star

