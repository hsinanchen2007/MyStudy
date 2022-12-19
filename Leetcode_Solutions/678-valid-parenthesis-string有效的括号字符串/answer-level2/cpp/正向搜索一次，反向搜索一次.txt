### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkValidString(string s) {
       int left=0;
       int right=0;
       int star=0;
       for(int i=s.size()-1;i>=0;i--){
           if(s[i]==')')right++;
           if(s[i]=='*')star++;
           if(s[i]=='('){
               if(right>0)right--;
               else if(star>0)star--;
               else return false;
           }
       }
       star=0;
       for(int i=0;i<s.size();i++){
           if(s[i]=='(')left++;
           if(s[i]=='*')star++;
           if(s[i]==')'){
               if(left>0)left--;
               else if(star>0)star--;
               else return false;
           }
       }
       return true;
    }
};
```