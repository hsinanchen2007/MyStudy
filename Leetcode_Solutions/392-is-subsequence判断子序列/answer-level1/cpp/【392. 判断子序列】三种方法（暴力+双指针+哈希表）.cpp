### 思路一：暴力
对于s中每个字符，在t中进行查找，flag标记是否找到，初始值为true（用于判断s为空字符串），在每次对s中的字符循环判断时
- 在t中开始查找前，设置flag = false
- 如果找到则设置flag = true并停止查找，然后判断s中下一个字符
- 如果遍历完t也没有找到，则flag依然为false，则直接return false

### 代码
时间复杂度：O(m + n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, i;
        bool flag = true;
        for (i = 0; i < s.size(); ++i) {
            flag = false;
            while (j < t.size()) {
                if (t[j++] == s[i]) {
                    flag = true;
                    break;
                }                     
            }            
            if (!flag) return false;                       
        }
        return flag;
    }
};
```

### 思路二：双指针

### 代码
```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size() && i < s.size(); ++j) {
            if (s[i] == t[j]) ++i;
        }
        return i == s.size();
    }
};
```

### 思路三：哈希表
对于大量s的检验，建立t的字符和位置的映射关系，相同字符存在有序的vector中，利用s和t中对应字符序列的有序性，对每一个s中的字符，在哈希表中进行查找，pre表示上一个查找字符的位置，因此每次在给定范围内查找第一个大于pre的值，如果找到，则表示存在，否则直接返回false。
### 代码
```c++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size = t.size(), pre = -1;
        unordered_map<char, vector<int>> ump;
        for (int i = 0; i < size; ++i) ump[t[i]].push_back(i);
        for (auto c : s) {
            auto it = upper_bound(ump[c].begin(), ump[c].end(), pre);
            if (it == ump[c].end()) return false;
            pre = *it;
        }
        return true;
    }
};
```

