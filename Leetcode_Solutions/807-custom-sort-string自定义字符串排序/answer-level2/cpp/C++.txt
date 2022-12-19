### 解题思路
先对T中出现的字母计数，然后遍历S，如果S中的字母c在T里面，则按照刚才的计数补充几个字母c到结果里面。最后再检查一下T还有哪些没有添加到结果里面的，补上就好。

### 代码

```cpp
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> count = vector<int>(26, 0);
        for (auto c : T ) {
            count[c - 'a']++;
        }
        string res;
        for (auto c : S) {
            for (int j=0; j<count[c-'a']; j++) {
                res.append(string(1, c));
            }
            count[c-'a'] = 0;
        }
        for (int i=0; i<26; i++) {
            for (int j=0; j<count[i]; j++) {
                res.append(string(1, i+'a'));
            }
        }
        return res;
    }
};
```