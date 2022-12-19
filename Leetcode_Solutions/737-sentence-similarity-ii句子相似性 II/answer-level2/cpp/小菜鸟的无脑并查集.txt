```
class Solution {
private:
    unordered_map<string, string> wordTable;
public:
    string FindRoot(const string &word)
    {
        if (!wordTable.count(word)) { // [word] == word
            return word;
        }
        return wordTable[word] = FindRoot(wordTable[word]);
    }

    void Union(const string &word1, const string &word2)
    {
        // map: 如果键已存在，会忽略，而不是覆盖
//        wordTable.insert(pair<string, string>(word1, word1));
//        wordTable.insert(pair<string, string>(word2, word2));
        string rootWord1 = FindRoot(word1);
        string rootWord2 = FindRoot(word2);
        if (rootWord1 != rootWord2) {
            wordTable[rootWord1] = rootWord2;
        }
    }

    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs)
    {
        if (words1.size() != words2.size()){
            return false;
        }
        for (const vector<string> &pair: pairs) {
            Union(pair[0], pair[1]);
        }
        bool result = true;
        for (int i = 0; i < words1.size(); ++i) {
            if (FindRoot(words1[i]) != FindRoot(words2[i])){
                result = false;
                break;
            }
        }
        return result;
    }
};
```
