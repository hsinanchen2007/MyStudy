采用贪心算法，用一个set来维护已经成立的结果:
```
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
    set<vector<int>> res;
    vector<int> path;

public:
    void comsum(vector<int>& candidates, int target, int idx){
        if(target<0) return;
        if(target==0){
            res.insert(path);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            path.push_back(candidates[i]);
            comsum(candidates, target-candidates[i],i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.rbegin(), candidates.rend());
        comsum(candidates, target, 0);

        vector<vector<int>> rres(res.begin(), res.end());
        return rres;
    }
};
```