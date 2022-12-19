## 思路一：滑动窗口


### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ump;
        int size = s.size(), res = 0;
        for (int i = 0, j = 0; j < size; ++j) {
            if (ump.find(s[j]) != ump.end()) { //之前出现过
                i = max(i, ump[s[j]] + 1); //i从相同字符下一个字符开始
            }
            res = max(res, j - i + 1); //计算以当前字符结尾长度
            ump[s[j]] = j;//插入哈希表
        }
        return res;
    }
};
```

### 另一种写法
每次向前移动结尾指针j，记录当前字符结尾最大长度，如果当前字符在前面出现过，则向前移动开始指针i，否则将当前字符插入哈希表，然后计算最大长度并且指向下一个字符。
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> uset;
        int size = s.size(), i = 0, j = 0, res = 0;
        while (i < size && j < size) {
            if (uset.count(s[j]) > 0) {
                uset.erase(s[i]);
                ++i;
            } else {
                uset.insert(s[j]);                
                res = max(res, j - i + 1);
                ++j;
            }
        }   
        return res;
    }
};
```
