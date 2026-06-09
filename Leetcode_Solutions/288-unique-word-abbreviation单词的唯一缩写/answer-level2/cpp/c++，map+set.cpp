```
class ValidWordAbbr {
public:
    map<string, set<string>> mset;

    ValidWordAbbr(vector<string> &dictionary) {
        int size = dictionary.size();
        for (int i = 0; i < size; ++i) {
            int len = dictionary[i].length();
            if (len < 3) {
                mset[dictionary[i]].insert(dictionary[i]);
            } else {
                mset[dictionary[i][0] + to_string(len - 2) + dictionary[i][len - 1]].insert(dictionary[i]);
            }
        }
    }

    bool isUnique(string word) {
        int len = word.length();
        string str = word;
        if (len >= 3) {
            str = word[0] + to_string(len - 2) + word[len - 1];
        }
        return !mset.count(str) || (mset[str].size() == 1 && mset[str].count(word));
    }
};
```