### 思路
1. 首先想到的是如果不管位置 `secret` 中猜对的数字，用个 `unordered_map<char, int>` 就可以求出
2. 再想到如果位置和数字都猜对，使用 `for` 循环便可求出
3. 同时在把它们从 `B` 中排除

### 答题
``` C++ []
string getHint(string secret, string guess) 
{
    int acnt = 0;
    int bcnt = 0;
    unordered_map<char, int> um;
    for (int i = 0; i < secret.size(); i++)
    {
        um[secret[i]]++;
        acnt += (secret[i] == guess[i]);
    }
    for (auto& c : guess)
    {
        bcnt += (um[c]-- > 0);
    }
    bcnt -= acnt;
    return to_string(acnt) + "A" + to_string(bcnt) + "B";
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

