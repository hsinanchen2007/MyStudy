![image.png](https://pic.leetcode-cn.com/a96176ea2c2540885a0387499be896f74f1020bf9f2df5355888a2861e83de9c-image.png)
解题思路：本题相当于26进制数的计算，相对简单。
```
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0;i<s.size();++i)
           res = 26*res + (s[i]-'A'+1);
        return res;
    }
```

