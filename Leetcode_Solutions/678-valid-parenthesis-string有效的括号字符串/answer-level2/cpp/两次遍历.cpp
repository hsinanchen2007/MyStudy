正向反向各一次遍历即可。

```
class Solution {
public:
    bool checkValidString(string s) {
        int size=s.size();
        int left=0,right=0,star=0;
        //正向遍历右括号的数量不能多于左括号和※数量之和
        for(int i=0;i<size;i++){
            if(s[i]=='(')left++;
            if(s[i]==')')right++;
            if(s[i]=='*')star++;
            if(right>left+star)return false;
        }
        left=0;right=0;star=0;
        //反向遍历左括号的数量不能多于右括号和※数量之和
        for(int i=size-1;i>=0;i--){
            if(s[i]=='(')left++;
            if(s[i]==')')right++;
            if(s[i]=='*')star++;
            if(left>right+star)return false;
        }
        return true;
    }
};
```
