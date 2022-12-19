### 思路
1. 对 `A` 和 `L` 计数
2. 如果该字母不是 `L` 就对其计数清零

### 答题
```C++ []
bool checkRecord(string s) 
{
    int cnt_A = 0;
    int cnt_L = 0;
    for (auto c : s)
    {
        cnt_A += (c == 'A');
        cnt_L = (c != 'L') ? 0 : cnt_L;
        cnt_L += (c == 'L');
        if (cnt_A > 1 || cnt_L > 2) return false;
    }
    return true;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

