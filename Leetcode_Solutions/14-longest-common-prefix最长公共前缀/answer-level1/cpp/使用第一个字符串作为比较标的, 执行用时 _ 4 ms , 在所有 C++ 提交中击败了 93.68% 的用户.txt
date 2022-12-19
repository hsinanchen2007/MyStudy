### 解题思路
直接用第一个作为标的.
如果有不一样的,或者说index已经超过了某个字符串(包括第一个)的长度,那就立刻返回.

最后的一个返回return strs[0]不会被调用到.

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        int n = strs.size();

        if (n == 0) return "";

        while(1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (index >= strs[i].length() || strs[i][index] != strs[0][index])
                {
                    return strs[0].substr(0, index);
                }
            }
            index++;
        }

        return strs[0];
    }
};
```