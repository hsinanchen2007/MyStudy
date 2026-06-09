### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isAnagram2(string s, string t) {

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }


    bool isAnagram(string s, string t) {

        vector<int> vs(26), vt(26);
        for (char c : s) ++vs[c - 'a']; // 计数
        for (char c : t) ++vt[c - 'a'];

        return vs == vt;
    }

};
```