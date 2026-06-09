### 解题思路
不需要找最短字符串

### 代码

```cpp
class Solution {
public:
   string longestCommonPrefix(vector<string>& strs) {
		if(0==strs.size()) return "";
        string ans="";
        int i=0;
        for(int j=0;strs[i][j]!='\0';j++){
            for(;i<strs.size();i++){
                if(strs[i][j]!=strs[0][j])
                break;
            }
            if(i==strs.size()){
                ans+=strs[0][j];
                i=0;
            }
            else break;
        }
        return ans;
	}
};
```