### 解题思路
此处撰写解题思路
char中讲各个字母计数，再与words中的字母计数比较，个数足够给words分配则可以被拼写并计数。
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int m[26];
        memset(m, 0, sizeof(m));
        for (char ch : chars) {
            m[ch-'a'] ++;
        }
        int ret = 0;
        for (auto word : words) {
            int temp[26];
            memcpy(temp, m, sizeof(m));
            bool canSpell = true;
            for (char ch : word) {
                if (temp[ch-'a'] == 0) {
                    canSpell = false;
                    break;
                }
                temp[ch-'a'] --;
            }
            if (canSpell) {
                ret += word.size();
            }
        }
        return ret;
    }
};
```