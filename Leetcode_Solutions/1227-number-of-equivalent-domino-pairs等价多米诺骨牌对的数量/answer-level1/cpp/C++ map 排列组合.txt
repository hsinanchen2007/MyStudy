```c++
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int num = 0;
        map<vector<int>, int> m;
        for (auto a : dominoes) {
            sort(a.begin(),a.end());
            ++m[a];
        }
        for (auto a : m) {
            if(a.second > 1) {
                num += a.second*(a.second-1)/2;
            }
        }
        return num;
    }
};
```
