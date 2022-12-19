### 思路
1. 统计各个字符个数
2. 判断是否有奇数个字符存在，如果有，可以让他作为中央字符
3. 因为奇数个字符有一个就够了，把所有字符的最大偶数个相加

### 答题
```C++ []
int longestPalindrome(string s)
{
    unordered_map<char, int> cnt;
    for (auto c : s)
    {
        cnt[c]++;
    }
    int ans = 0;
    int odd = 0;
    for (auto& p : cnt)
    {
        odd = (odd == 1 || p.second % 2 == 1);
        ans += (p.second / 2 * 2);
    }
    return ans + odd;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

