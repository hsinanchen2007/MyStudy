### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
第一次双百，记录一下，利用sort函数排序后，直接在第一个和最后一个中获取最长前缀

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1) return "";
        if(strs.size() == 1) return *strs.begin();
        sort(strs.begin(), strs.end());
        auto iter = strs.begin();
        auto scan = strs.end() - 1;
        string s = *iter, e = *scan;
        string per = "";
        int i = 0;
        while(1) {
            if(s[i] != e[i] || i == s.size() || i == e.size()) break;
            i++;
        }
        if(i != 0) per = s.substr(0, i);
        return per;
    }
};
```