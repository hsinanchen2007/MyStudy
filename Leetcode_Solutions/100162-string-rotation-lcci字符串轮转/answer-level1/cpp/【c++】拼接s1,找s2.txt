拼接s1，若能找到s2，则为真
注意考虑为空的特殊情况
```
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        // "",""
        if(s2.length()==0 && s1.length()==0){
            return true;
        }
        // 一个""
        if(s2.length()==0){
            return false;
        }
        // 拼接s1，若能在s1中找到s2，即为真
        s1+=s1;
        auto res = s1.find(s2);
        if(res == string::npos){
            return false;
        }
        return true;
    }
};
```
