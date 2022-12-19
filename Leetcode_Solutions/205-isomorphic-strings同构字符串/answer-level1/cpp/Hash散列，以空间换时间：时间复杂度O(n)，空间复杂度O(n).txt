![捕获.PNG](https://pic.leetcode-cn.com/44756c985e1b4f0ff6fb5dc9fcff49e1ea2ad9805f854258f497deae5cbd0977-%E6%8D%95%E8%8E%B7.PNG)

### 解题思路
通过一次遍历判断s与t是否同构。
1) 构建hash表，作为s中的字符到t中字符的映射
2) 从起始位置开始遍历s中的字符，检查当前字符是否已经与t中某字符构成映射关系：
    若已构成映射关系，且t中同样位置的字符正是s当前字符的映射，则去比较s中下一个字符，否则直接返回false；
    若未构成映射关系，则检查t中同位置字符是否已在映射集中，若t中同位置字符已在映射集中，则说明s中有至少两个不同的字符会映射到t中同一字符，与题设矛盾，返回false，否则，建立s中当前位置字符与t中同位置字符的映射关系，将此映射关系加入到映射集中。
3) 若能够顺利结束遍历，则s与t同构，返回true

### 代码

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // if (s.length() != t.length()) return false;
        int len = s.length();
        unordered_map<char, char> hash;
        unordered_map<char, bool> isMapped;
        for (int i = 0; i < len; i++) {
            if (hash.find(s[i]) != hash.end()) {
                if (hash[s[i]] != t[i])
                    return false;
            } else {
                if (isMapped.find(t[i]) != isMapped.end()) return false;
                hash[s[i]] = t[i];
                isMapped[t[i]] = true;
            }
        }
        return true;
    }
};
```