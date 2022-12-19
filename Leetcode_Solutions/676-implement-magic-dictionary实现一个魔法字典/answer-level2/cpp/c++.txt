暂时没有太高效的解法，按长度将word存入map中， 遍历指定长度的vector即可
```
class MagicDictionary {
public:
    map<int, vector<string>> mmap;

    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); ++i) {
            mmap[dict[i].length()].push_back(dict[i]);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.length();
        if (!mmap.count(len)) {
            return false;
        }
        vector<string> &v = mmap[word.length()];
        for (int i = 0; i < v.size(); ++i) {
            int diff = 0;
            for (int j = 0; j < len; ++j) {
                if (word[j] != v[i][j]) {
                    diff++;
                    if (diff == 2) {
                        break;
                    }
                }
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }
};
```