### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        if(strs.size()==1)
            return strs[0];
        int i(0);
        string s;
        for(int j=0;;j++){
            while(i<strs.size()-1&&strs[i][j]!=NULL&&strs[i][j]==strs[i+1][j]){
                i++;
            }
            if(i==strs.size()-1){
                s+=strs[0][j];
                i=0;
            }
            else
                break;
        }
        return s;
    }
};
```