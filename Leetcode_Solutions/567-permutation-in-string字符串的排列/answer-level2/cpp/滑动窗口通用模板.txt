## 问题描述
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

![](https://pic.leetcode-cn.com/0415ce5659d4ba857c38ad7c998060ae92826a1ec3db47fb8f63059a2ab54ffd.png)

[字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/ "字符串的排列")

## 解决方法

### 滑动窗口

滑动窗口可以解决的问题有（不定期更新）：

- [最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/ "最小覆盖子串")

- [找到字符中所有的字符异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/ "找到字符中所有的字符异位词")

- [字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/solution/ "字符串的排列")

- [无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/ "无重复字符的最长子串")

滑动窗口通用思想：

- 维护两个窗口，`needs`和`window`，`needs`统计`T`中所有字符出现的个数，`window`表示当前窗口下包含`needs`中字符的个数

- 维护两个指针，`left`和`right`

- `right`指针向后移动，不断扩大窗口直到当前窗口包含了`t`中所有字符

- `left`指针向后移动，直至当前窗口内的字符串不再符合要求（未能包含`T`中所有字符）

- 直至找到解，否则重复3-4

通用模板：

```
class Solution {
public:
    void slideWindow(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (auto i:s1)needs[i]++;
        int size = s2.size(), left = 0, right = left;
        int match = 0;
        while (right < size) {
            char t = s2[right];
            if (needs.count(t)) {
                window[t]++;
                if (window[t] == needs[t])match++;
            } 
            /*
             * 处理别的情况
             * */
            right++;
            while (match == needs.size()) {
                /*
                 * 终止条件撰写
                 * */
                char t2 = s2[left];
                if (needs.count(t2)) {
                    window[t2]--;
                    if (window[t2] < needs[t2])match--;
                }
                left++;
            }
        }
    }
};
```

**本题代码**：


```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (auto i:s1)needs[i]++;
        int size = s2.size(), left = 0, right = left;
        int match = 0;//用来判断当前窗口是否包含needs中所有字符
        while (right < size) {
            char t = s2[right];
            if (needs.count(t)) {
                window[t]++;
                if (window[t] == needs[t])match++;
            } else {
                match = 0;
                window.clear();
                left = right + 1;
            }
            right++;
            while (match == needs.size()) {
                if (right - left == s1.size())return true;
                char t2 = s2[left];
                if (needs.count(t2)) {
                    window[t2]--;
                    if (window[t2] < needs[t2])match--;
                }
                left++;
            }
        }
        return false;
    }
};
```


个人网址：[liyiping](https://liyiping.cn)