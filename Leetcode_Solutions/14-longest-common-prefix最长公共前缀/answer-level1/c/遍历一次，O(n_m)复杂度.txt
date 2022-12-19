### 解题思路
n为字符串个数，m为第一个字符串的长度

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string re;
        if (strs.empty()) return re;
        //长度
        int end = strs[0].size()-1;
        for (int i=1; i<strs.size(); i++) {
            if (end < 0) break;
            if (strs[i].size() <= end) end = strs[i].size()-1;
            int ori_end = end;
            for (int j=ori_end; j>=0; j--) {
                if (strs[i-1][j] != strs[i][j]) {
                    end = j-1;
                }
            }
        }
        end += 1;
        return end==0 ? re : strs[0].substr(0, end);
    }
};
```