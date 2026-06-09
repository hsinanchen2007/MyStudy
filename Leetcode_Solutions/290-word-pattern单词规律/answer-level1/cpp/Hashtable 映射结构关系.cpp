### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int size = str.size();
        vector<string> words;
        int startPos = 0;
        for(int i = 0; i < size; i ++){
            if(str[i] == ' ') {
                words.push_back(str.substr(startPos, startPos > 0 ? i - startPos : i));
                startPos = i + 1;
            }
        }
        words.push_back(str.substr(startPos, size - 1));

        if(pattern.size() != words.size()){
            return false;
        }

        unordered_map<char, int> upp;
        vector<int> c1;
        for(int i = 0; i< pattern.size(); i++) {
            if(upp.find(pattern[i]) != upp.end()) {
                c1.push_back(upp[pattern[i]]);
            } else {
                upp[pattern[i]] = i;
                c1.push_back(i);
            }
        }

        unordered_map<string, int> upw;
        vector<int> c2;
        for(int i = 0; i < words.size(); i++) {
            if(upw.find(words[i]) != upw.end()) {
                c2.push_back(upw[words[i]]);
            } else {
                upw[words[i]] = i;
                c2.push_back(i);
            }
        }

        for(int i = 0; i < c1.size(); i++) {
            if(c1[i] != c2[i]) {
                return false;
            }
        }

        return true;

    }
};
```