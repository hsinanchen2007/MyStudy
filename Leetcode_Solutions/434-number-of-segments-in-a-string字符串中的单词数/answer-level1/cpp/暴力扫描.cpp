### 解题思路
读第一个非空，然后本单词结尾+1，作为下一次输入开始

### 代码

```cpp
class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) {
            return 0;
        }
        int begin = 0;
        int end = 0;
        int count = 0;
        while (begin < s.size()) {
            if (s[begin] != ' ') {
                begin = findnext(s, begin + 1);
                count++;
            } else {
                begin++;
            }
            
        }
        return count;
    }
    int findnext(string& s, int begin) {
        int pos = begin;
        while ((s[pos] != ' ') && (pos < s.size())) {
            pos++;
        }
        return pos;
    }
};
```