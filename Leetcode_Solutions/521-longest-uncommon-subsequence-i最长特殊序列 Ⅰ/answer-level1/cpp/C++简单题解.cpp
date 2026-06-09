![image.png](https://pic.leetcode-cn.com/cd875837b6cc9eb7eff4809784a9532486aa7916af186747ccace041f7ea14fa-image.png)
解题思路：两字符串长度不等，特殊序列即为较大字符串，若长度相等切字符串相同返回-1，若长度相等，字符串不同，返回a或b长度。
```
    int findLUSlength(string a, string b) {
        if(a.size() != b.size()) return max(a.size(),b.size());
           if(a == b) return -1;
             return a.size();
    }
```

