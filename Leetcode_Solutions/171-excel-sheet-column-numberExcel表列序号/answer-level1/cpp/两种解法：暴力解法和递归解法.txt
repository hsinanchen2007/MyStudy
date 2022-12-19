### 解题思路

1，暴力解法思路比较简单，只是把十进制换成了26进制
感觉问题考察的点很单调，题目意思也没有表达清楚，看题目我还以为是根据输入来决定列数的名称呢
2，顺便练习了一下递归调用，使用int函数返回值时会出现溢出现象，不知为何：同样是int类型返回值，解法一为何没有溢出，还望有大佬指点。
### 代码

```暴力解法 []
class Solution {
public:
    int titleToNumber(string s) {
        while (s.empty())
            return 0;
        int ans=0;
        for (char c:s){
            ans=ans*26+(c-'A'+1);
        }
        return ans;
    }
};
```
```递归 []
class Solution {
public:
    double recursion(string s){
        if (s.length()==1) return s[0]-'A'+1;
        return (recursion(s.substr(0, s.length()-1))*26+s[s.length()-1]-'A'+1);
    }
    double titleToNumber(string s) {
        while (s.empty())
            return 0;
        return recursion(s);
    }
};
```
