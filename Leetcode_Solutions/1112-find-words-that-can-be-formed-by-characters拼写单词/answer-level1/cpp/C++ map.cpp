### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> table;
        for (int i=0; i<chars.size(); i++) {
            if (table.find(chars[i]) != table.end()) {
                table[chars[i]] += 1;
            }
            else {
                table[chars[i]] = 1;
            }
        }

        int ans = 0;
        unordered_map<char, int> cur;
        for (int i=0; i<words.size(); i++) {
            cur = table;
            for (int j=0; j<words[i].size(); j++) {
                if (cur.find(words[i][j])==cur.end()) {
                    break;
                } else {
                    cur[words[i][j]]--;
                    if (cur[words[i][j]]<0) {
                        break;
                    }
                }
                if (j==words[i].size()-1) {
                    ans += words[i].size();
                }
            }
        }
        return ans;



    }
};
```