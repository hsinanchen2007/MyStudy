### 解题思路
对所有元音做异或，hashmap保存每个异或值val的位置,countmap[0] = -1;
对s中每个位置i都判断当前val值，如果当前位置val在hashmap中存在result = max(result, i - countmap[val]);
如果当前字符是元音且val在hashmap中不存在，填到hashmap中

### 代码

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int val = 0;
        unordered_map<int,int> countmap;
        countmap[0] = -1;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!='a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
                if (countmap.count(val)) result = max(result, i - countmap[val]);
                continue;
            }
            val ^= s[i];
            if (countmap.count(val)) {
                result = max(result, i - countmap[val]);
            } else {
                countmap[val] = i;
            }
        }
        return result;
    }
};
```