### 解题思路
技巧还是蛮多的，还需要慢慢消化

### 代码

```cpp
#if 0
//贪心
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        int N = dict.size();
        vector<int> prefix(N, 0);
        vector<string> result(N);

        for (int i = 0; i < N; ++i) {
            result[i] = compress(dict[i], 0);
        }

        for (int i = 0; i < N; ++i) {
            while (1) {
                unordered_set<int> dup;

                for (int j = i + 1; j < N; ++j) {
                    if (result[i] == result[j]) {
                        dup.insert(j);
                    }
                }

                if (dup.empty()) {
                    break;
                }

                dup.insert(i);

                for (auto each : dup) {
                    result[each] = compress(dict[each], ++prefix[each]);
                }
            }

        }

        return result;
    }
private:
    string compress(string word, int pos)
    {
        if (word.size() - pos <= 3) {
            return word;
        }

        return word.substr(0, pos + 1) + to_string(word.size() - pos - 2) + word.back();
    }
};

//分组+最短公共前缀
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        unordered_map<string, vector<indexedWord>> groups;
        vector<string> result(dict.size());

        int index = 0;
        for (auto each : dict) {
            string key = compress(each, 0);
            groups[key].push_back(indexedWord(index, each));
            index++;
        }

        for (auto group : groups) {
            vector<indexedWord> sortedWords = group.second;
            sort(sortedWords.begin(), sortedWords.end());

            vector<int> lcp(sortedWords.size(), 0);
            for (int i = 1; i < sortedWords.size(); ++i) {
                lcp[i] = longestCommonPrefix(sortedWords[i].word, sortedWords[i - 1].word);
                lcp[i - 1] = max(lcp[i - 1], lcp[i]);
            }

            for (int i = 0; i < sortedWords.size(); ++i) {
                result[sortedWords[i].index] = compress(sortedWords[i].word, lcp[i]);
            }
        }

        return result;
    }
private:
    struct indexedWord {
        indexedWord(int idx, string w) : index(idx), word(w) {}
        int index;
        string word;
        bool operator < (const indexedWord& rhs) const {
            return word < rhs.word;
        }
    };

    string compress(string word, int pos)
    {
        if (word.size() - pos <= 3) {
            return word;
        }

        return word.substr(0, pos + 1) + to_string(word.size() - pos - 2) + word.back();
    }

    int longestCommonPrefix(string a, string b)
    {
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }

        return i;
    }
};
#endif

//分组+trie
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict)
    {
        unordered_map<string, vector<indexedWord>> wordsMap;
        vector<string> result(dict.size());

        int index = 0;
        for (auto each : dict) {
            string key = compress(each, 0);
            wordsMap[key].push_back(indexedWord(index, each));
            index++;
        }

        for (auto group : wordsMap) {
            vector<indexedWord> wordsArray = group.second;
            trie *root = new trie();

            for (auto word : wordsArray) {
                trie *cur = root;
                for (auto ch : word.word) {
                    if (cur->next[ch - 'a'] == NULL) {
                        cur->next[ch - 'a'] = new trie();
                    }
                    
                    cur = cur->next[ch - 'a'];
                    cur->count++;
                }
            }

            for (auto word : wordsArray) {
                trie *cur = root;
                int i = 0;
                for (auto ch : word.word) {
                    if (cur->count == 1) {
                        break;
                    }
                    cur = cur->next[ch - 'a'];
                    i++;
                }

                result[word.index] = compress(word.word, i - 1);
            }
        }

        return result;
    }
private:
    struct trie {
        trie* next[26];
        int count;
        trie() {
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
            count = 0;
        }
    };

    struct indexedWord {
        indexedWord(int idx, string w) : index(idx), word(w) {}
        int index;
        string word;
        bool operator < (const indexedWord& rhs) const {
            return word < rhs.word;
        }
    };

    string compress(string word, int pos)
    {
        if (word.size() - pos <= 3) {
            return word;
        }

        return word.substr(0, pos + 1) + to_string(word.size() - pos - 2) + word.back();
    }
};
```