# 一、暴力法
和其他题解类似，从字符串开头找到最长的回文子串。
```c++
string shortestPalindrome(string s)
{
    int n = s.length();
    string re(s.rbegin(), s.rend());
    for (int i = 0; i < n; i++) {
        if (s.substr(0, n - i) == re.substr(i))
            return re.substr(0, i) + s;
    }
    return "";
}
```
时间复杂度为$O(n^2)$

# 二、优化暴力法(哈希)
上面的 `s.substr(0, n - i) == re.substr(i)` 十分耗时，并且字符串只比上一个循环的长度多一。于是我们可以利用之前的比较结果，使用哈希进行优化：
```c++
string shortestPalindrome(string s)
{
    string re(s.rbegin(), s.rend());
    int n = s.length();
    unsigned int seed = 5, hash = 0, hash_re = 0, max_length = 0, base = 1;
    for(int i = 0; i < n; i++){
        hash = hash * seed + s[i] - 'a' + 1;
        hash_re += base * (re[n - i - 1] - 'a' + 1);
        base *= seed;
        if(hash == hash_re)
            max_length = i;
    }
    return re.substr(0, n - max_length - 1) + s;
}
```
该解法存在一定问题，理论上测试集足够大的情况下会出现冲突，不过概率十分小。