### 解题思路
遍历一遍就好

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int flag=1;
        for(int i=0;i<s.size();i++){
            string temp;
            if(s[i]==' ')
                continue;
            else{
                while(i<s.size()&&s[i]!=' ')
                    temp+=s[i++];
                if(flag==1){
                    res=temp+res;
                    flag=0;
                }
                else
                    res=temp+' '+res;
            }
        }
        return res;
    }
};
```