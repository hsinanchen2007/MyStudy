### 解题思路
直观的看，可以看到递归结构。
如果s的首字母和t的首字母相同，则只需判断s.substr(1,s.length())和t.substr(1,t.length())是否相同。
如果s的首字母和t的首字母不同，则只需判断s和t.substr(1,t.length())是否相同。

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
    
        int it=0;
        int is=0;
        while(is<s.length()&&it<t.length()){
        if(s[is]!=t[it])
           it ++;
        else{
           is ++;
           it ++;
        }
        }
        
        return s.length()==is;
    }
};
```