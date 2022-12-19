### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() <= 0) return "";

        int min = strs[0].size();
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() > min) {
                min = strs[i].size();
            }
        }

        int index = 0;
        string s = "";
        while (index < min) {
            bool end = false;
            char temp = strs[0][index];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][index] != temp) {
                    end = true;
                }
            }
            if (end) {
                break;
            }
            else {
                s += temp;
                index++;
            }
        }

        return s;
    }
};
```