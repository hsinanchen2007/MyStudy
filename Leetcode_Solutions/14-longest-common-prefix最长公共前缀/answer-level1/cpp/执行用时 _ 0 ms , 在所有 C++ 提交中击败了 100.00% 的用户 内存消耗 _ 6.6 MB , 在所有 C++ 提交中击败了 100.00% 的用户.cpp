### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        int n = strs.size();
        if(n == 0) return "";
        if(n == 1) return strs[0];

        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 0; j < n; j++){
                if(strs[j][i] != strs[0][i]){
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};
```