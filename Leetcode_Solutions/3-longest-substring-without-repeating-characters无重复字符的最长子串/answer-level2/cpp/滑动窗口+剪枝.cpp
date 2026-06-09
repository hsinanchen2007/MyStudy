### 解题思路
滑动窗口+剪枝
，利用两个指针，存放当前已获取的s，然后再判断下一个是否是重复的，如果是重复的，则将beginIndex往前追加。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int beginIndex = 0;
        int endIndex = 1;
        int maxCount = 0;
        while (endIndex <= s.size() && beginIndex <= s.size()) {
            string str = s.substr(beginIndex, endIndex - beginIndex);
            string::size_type position = str.find(s[endIndex]);
            if (position != str.npos) {
                beginIndex = beginIndex + position + 1;
            }
            endIndex++;
            maxCount = max(maxCount, (int)str.size());
        }
        return maxCount;
    }
};
```