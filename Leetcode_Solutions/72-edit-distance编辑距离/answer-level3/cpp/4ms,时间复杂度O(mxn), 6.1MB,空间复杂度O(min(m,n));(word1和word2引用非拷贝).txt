```
class Solution {
public:
    int minDistance(string& word1, string& word2) {
        if(word1.size() > word2.size()){
            return minDistance(word2,word1);
        }
        if(word1.empty()){
            return word2.size();
        }
        int n[word1.size()+1];
        for(int i = 0; i <= word1.size(); ++i){
            n[i] = i;
        }
        for(int i = 0; i < word2.size();++i){
            n[0] = i;
            int p = n[0];
            for(int j = 1; j <= word1.size(); ++j){
                int t = n[j];
                if(word1[j-1] == word2[i]){
                    n[j] = min(p,n[j]+1);
                }
                else{
                    n[j] = min(n[j-1],min(p,n[j]))+1;
                }
                p = t;
            }
        }
        return n[word1.size()];
    }
};
```
