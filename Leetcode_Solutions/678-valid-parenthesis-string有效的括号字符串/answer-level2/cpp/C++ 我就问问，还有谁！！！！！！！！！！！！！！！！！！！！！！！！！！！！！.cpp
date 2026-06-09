### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int ma=0;//当前位置最大的未匹配的'('个数
        int mi=0;//当前位置最小的未匹配的'('个数
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                ma++;
                mi++;
            }
            else if(s[i]==')'){
                if(ma<=0) return false;
                else{
                    ma--;
                    if(mi>0) mi--;
                }
            }
            else{
                ma++;
                if(mi>0) mi--;
                
            }
        }
        return ma>=0&&mi<=0;
    }
};
```