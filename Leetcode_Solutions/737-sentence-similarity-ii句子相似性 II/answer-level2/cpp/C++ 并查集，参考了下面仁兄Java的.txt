```
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }

        if (words1 == words2) {
            return true;
        }

        map<string, string> unionSet;
        for (int i = 0; i < pairs.size(); i++) {
            vector<string> &pair = pairs[i];
            if (unionSet.find(pair[0]) == unionSet.end()) {
                unionSet.insert(make_pair(pair[0], pair[0]));
            }
            if (unionSet.find(pair[1]) == unionSet.end()) {
                unionSet.insert(make_pair(pair[1], pair[1]));
            }
            unionSet[getParent(unionSet, pair[0])] = getParent(unionSet, pair[1]);
        }

        for (map<string, string>::iterator iter = unionSet.begin(); iter != unionSet.end(); iter++) {
            cout << iter->first << "  " << iter->second << endl;
        }
        for (int i = 0; i < words1.size(); i++) {
            string w1 = words1[i];
            string w2 = words2[i];
            if (w1 == w2) {
                continue;
            }

            if (unionSet.find(w1) == unionSet.end() || unionSet.find(w2) == unionSet.end() || getParent(unionSet, w1) != getParent(unionSet, w2)) {
                return false;
            }
        }

        return true;
    }

    string getParent(map<string, string> &unionSet, string word)
    {
        while(unionSet[word] != word) {
           word = unionSet[word];
        }
        return word;
    }
};
```
