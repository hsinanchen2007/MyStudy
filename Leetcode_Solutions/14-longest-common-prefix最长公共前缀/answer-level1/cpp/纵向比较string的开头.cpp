### 解题思路
比较所有string的第一个字符，如果它们相等则提出这个字符；再比较所有string的第二个字符...直到所有string第N个字符不相同时结束。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        string res="";
        int min=strs[0].length();
        for(int i=1;i<strs.size()-1;++i){
            if(min<strs[i].length()) min=strs[i].length();
        }
        if(!min) return "";
        for(int n=0;n<min;++n){
            bool flag=true;
            for(int i=0;i<strs.size()-1;++i){
                if(strs[i][n]!=strs[i+1][n]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                res += strs[0][n];
            } else{
                break;
            }
        }
        return res;
    }
};
```