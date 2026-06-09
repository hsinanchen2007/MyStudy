```
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int maxindex1 = -1, maxindex2 = -1;
        int minDist = INT_MAX;
        for(int i  = 0; i < words.size(); ++i){
            if(words[i] == word1){
                if(maxindex2 != -1) minDist = min(minDist, i - maxindex2);
                maxindex1 = i;
            }else if(words[i] == word2){
                if(maxindex1 != -1) minDist = min(minDist, i - maxindex1);
                 maxindex2 = i;
            }
        }
        return minDist;
    }
};
```