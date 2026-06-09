### 解题思路
注意字符串全相同时的边界检查

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i=0;
        if(strs.size()==0){
            return "";
        }
        else if(strs.size()==1){
            return strs[0];
        }
        else while(strs[0][i]){
            for(int j=1;j<strs.size();j++){
                if(strs[0][i]==strs[j][i]){
                    continue;
                }
                else{
                    result = strs[0].substr(0,i);
                    return result;
                }
            }

            i++;
        }


        if(strs[0].size()<i){
            return "";
        }
        else{
            return strs[0];
        }
        
    }
};
```