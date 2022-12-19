```
class WordDistance {
private:
    unordered_map<string, vector<int> > mp;
public:
    WordDistance(vector<string>& ws) {
        int index = 0;
        for(auto w : ws) mp[w].push_back(index++);
    }
    
    int shortest(string word1, string word2) {
        vector<int> index1 = mp[word1], index2 = mp[word2];
        int minDist = INT_MAX;
        for(auto i : index1) for(auto j : index2) minDist = min(minDist, abs(i - j));
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
```