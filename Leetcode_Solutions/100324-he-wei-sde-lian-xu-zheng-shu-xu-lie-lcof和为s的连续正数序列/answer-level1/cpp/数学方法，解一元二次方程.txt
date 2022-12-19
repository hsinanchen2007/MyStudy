```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int S = target;
        vector<vector<int>>ans;
        for(int a1 = 1; a1 <= S/2; a1++){
            long long delta = (long long)(2*a1-1)*(2*a1-1) + 8*S;
            int n = (sqrt(delta) - (2*a1 - 1))/2;
            if(2*S == 2*a1*n + n*(n-1)){
                vector<int>an;
                for(int i = a1; i < a1 + n; i++) an.push_back(i);
                ans.push_back(an);
            }
        }
        return ans;
    }
};
```