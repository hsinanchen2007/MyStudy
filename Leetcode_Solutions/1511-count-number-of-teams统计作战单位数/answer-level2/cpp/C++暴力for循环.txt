```
class Solution {
public:
    int numTeams(vector<int>& rating) {
        if(rating.size() < 3) return 0;
        int res = 0;
        for(int i = 0; i < rating.size()-2; ++i){
            for(int j = i; j < rating.size()-1; ++j){
                for(int k = j; k < rating.size(); ++k){
                    if(rating[i] > rating[j] && rating[j] > rating[k])
                        res++;
                    if(rating[i] < rating[j] && rating[j] < rating[k])
                        res++;
                }
            }
        }
        return res;
    }
};
```