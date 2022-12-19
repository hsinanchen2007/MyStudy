### 解题思路
递归，主要是对*的处理;

### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()){//边界
            return s.empty();
        }
        //当前这一位是否能匹配上
        bool current_match=(s[0]==p[0]||p[0]=='.');
        if(p.size()>=2&&p[1]=='*'){
            if(s.empty()){
                //s为空,*只能匹配0个字符
                return isMatch(s,p.substr(2));
            }
            else{
                //s不为空,*可以匹配0个或多个字符
                return isMatch(s,p.substr(2))||(current_match&&isMatch(s.substr(1),p));
            }
        }
        else{
            //s为空,p中此时没有匹配0-多个的字符的能力(不含*),所以不能匹配
            if(s.empty()){
                return false;
            }
            //s不为空,此时是一对一的匹配,则继续向下匹配
            else{
                return current_match&&isMatch(s.substr(1),p.substr(1));
            }
        }
    }
};
```