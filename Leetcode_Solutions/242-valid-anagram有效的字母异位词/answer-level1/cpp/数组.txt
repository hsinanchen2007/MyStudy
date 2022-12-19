### 解题思路
遍历一次，用两个数组记录26个小写字母出现的次数
判断数组的26个下标是否存在不等的情况，存在返回false，否则返回true
### 代码

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int sArr[26] = {0};
        int tArr[26] = {0};
        for (int i=0; i<s.size(); i++)
            sArr[s[i]-97]++;
        for (int i=0; i<t.size(); i++)
            tArr[t[i]-97]++;
        for (int i=0; i<26; i++)
            if (sArr[i] != tArr[i])
                return false;
        return true;
    }
};
```