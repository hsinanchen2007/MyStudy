```
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> count;
        map<int,vector<int>> curr;
        
        for(auto a : arr){
            count[a]++;
        }
        for(auto c : count){
            curr[c.second].push_back(c.first);
        }
        for(auto c : curr){
            if(c.second.size() > 1){
                return false;
            }
        }
        
        return true;
    }
};
```