### 解题思路
此处撰写解题思路
..
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        if(n == 0) return res;
        int num = 0;
        int first_len = strs[0].size();
        while(1){
            if(num >= first_len) break;
            char temp;
            for(int i = 0; i < n; i++){
                if(num >= strs[i].size()) return res;
                if(i == 0) temp = strs[i][num];
                else
                    if(strs[i].size() <= num || strs[i][num] != temp) return res;
            }
            res += temp;
            num++;
        }
        return res;
    }
};
```