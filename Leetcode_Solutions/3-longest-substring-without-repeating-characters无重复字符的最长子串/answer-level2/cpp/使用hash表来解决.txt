### 解题思路
此处撰写解题思路
复杂度是o(n)的，原理是迭代一个元素，以该元素为起点，将不同的value保存在一个hash表内。当发现冲突后，使用ret保存当前的最大值，然后将发生冲突的value从hash_code中弹出。使用普通的set，二叉树。复杂度为n * log(n).
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ret = 0;
        unordered_set<char> saved;
        string::iterator begin, end;
        begin = end = s.begin();
        while (end != s.end()) {
            if (!saved.count(*end)) {
                saved.emplace(*end++);
                continue;
            }
            ret = std::max(ret, static_cast<int>( saved.size()));
            while (*begin != *end) {
                saved.erase(*begin++);
            }
            ++begin;
            ++end;
        }
        return std::max(ret, static_cast<int>( saved.size()));
    }
};

```