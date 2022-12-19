```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int len = 1, sum = 1, temp;
        while ((target - sum) / ++len) {
            if ((target - sum) % len == 0) {
                temp = (target - sum) / len;
                res.insert(res.begin(),vector<int>());
                for (int i=1;i<=len;i++)
                    res[0].push_back(temp++);
            }
            sum += len;
        }
        return res;
    }
};
```
