### 解题思路

使用一个Map记录每个字符的位置，遇到已经存在map中的字符表示遇到相同的字符，这时候，只需要将左指针设置为重复字符的右边。
如果没重复，则继续记录位置。

最大长度则是左右指针的最大距离。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> hashMap;
        int len = 0, l = 0, r = 0;
        while(r < s.size()) {
            if (hashMap.find(s[r]) != hashMap.end()) {
                // 找到已经重复元素，l开始移动到重复的字符左边
                l = max(l, hashMap[s[r]] + 1);
            }
            hashMap[s[r]] = r;
            r++;
            len = max(len, r - l);
        }
        return len;
    }
};
```