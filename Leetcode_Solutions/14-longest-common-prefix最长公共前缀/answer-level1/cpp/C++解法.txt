### 解题思路
第一次写题解，希望以后能够坚持下来，刷题，写题解。
我的思路：
1. 首先找到所有字符串里最短那一个，这个时候可以知道我们稍后循环遍历时的一个终止条件
2. 然后取第一个字符串的字符，对其他所有字符串来遍历操作，如果当前字符所有都相同，则继续
3. 直到遇到不一样的字符或者到末尾

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return string("");
        int minLen = INT_MAX;
        // 找到最短的字符串长度
        for (int i = 0; i < strs.size(); i++)
            if(strs[i].size() < minLen)
                minLen = strs[i].size();
        bool flag = false;
        int pos = 0;
        for (int i = 0; i < minLen; i++)
        {   
            char c = strs[0][i];   
            for (int j = 0; j < strs.size(); j++)
            {
                if(strs[j][i] != c) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
            pos++;
        }
        string prefix = string(strs[0], 0, pos);
        return prefix;
    }
};
```