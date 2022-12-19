
```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int sum = 0;
        vector<int> cur;
        dfs(rating, true, cur, 0, sum);
        dfs(rating, false, cur, 0, sum);
        return sum;
    }
    
    void dfs(vector<int>& rating, bool dir, vector<int>& cur, int begin, int& sum) {
        if (cur.size() == 3) {
            sum++;
            return;
        }
        
        for (int i = begin; i < rating.size(); ++i) {
            if (cur.size() == 0 || dir && rating[i] > cur.back() || !dir && rating[i] < cur.back()) {
                cur.push_back(rating[i]);
                dfs(rating, dir, cur, i + 1, sum);
                cur.pop_back();
            }
        }
    }
};
```