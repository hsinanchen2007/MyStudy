### 解题思路
思路很简单，对vector容器排序，取出首尾string得到最长公共前缀就可以了。

![捕获.PNG](https://pic.leetcode-cn.com/412aa998432a01aabb328941f2f548230c5266de40a411dee4f7b8a74f3e5f3b-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    string CommonTwoStr(const string& str1, const string& str2)
    {
        string tmp = "";
        int n = 0;
        int minSize = min(str1.size(), str2.size());
        for (int i = 0; i <= minSize; ++i)
        {
            if (str1[i] != str2[i])
                break;
            ++n;
        }
        return str1.substr(0, n);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        else if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string result = CommonTwoStr(strs[0], strs[strs.size() - 1]);
        return result;
    }
};