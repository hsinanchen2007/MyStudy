建立set型vector存储字母，遍历字符串，第一个字符确定哪一行，之后字符确定是否在同一行

代码：
```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<set<int> > key;
        set<int> key_1 {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<int> key_2 {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<int> key_3 {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        key.push_back(key_1);
        key.push_back(key_2);
        key.push_back(key_3);
        int num = words.size();
        for (int i = 0; i < num; i++) {
            int len = words[i].length();
            for (int j = 0; j < 3; j++) {
                if (key[j].find(words[i][0]) != key[j].end() || key[j].find(words[i][0] + 32) != key[j].end()) {
                    bool single = true;
                    for (int k = 1; k < len; k++) {
                        if (key[j].find(words[i][k]) == key[j].end() && key[j].find(words[i][k] + 32) == key[j].end()) {
                            single = false;
                            break;
                        }
                    }
                    if (single)
                        ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
```
