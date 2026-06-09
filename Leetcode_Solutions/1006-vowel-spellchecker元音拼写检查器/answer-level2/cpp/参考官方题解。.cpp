参考官方题解c++实现。我自己写卡在了元音的判断哪里。没想到官方的'*'替代的方法。

```
class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> hash1(wordlist.begin(), wordlist.end());
        unordered_map<string, string> hash2;
        unordered_map<string, string> hash3;
        vector<string> res(queries.size());
        string str = "";
        for (auto s : wordlist) {
            str = s;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (hash2.find(str) == hash2.end()) hash2[str] = s;
            trans(str);
            if (hash3.find(str) == hash3.end()) hash3[str] = s;
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (hash1.count(queries[i])) {
                res[i] = queries[i]; continue;
            }
            str = queries[i];
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (hash2.count(str))
                res[i] = hash2[str];
            else {
                trans(str);
                if (hash3.count(str)) res[i] = hash3[str];
            }
        }
        return res;
    }
    void trans(string& s) {
        for (auto& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
    }
};
```