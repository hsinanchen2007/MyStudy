class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int a = 1, b = 2;
        int k = 0;

        for (int i = 1; i < target - 1; i++) {
            if ((a + b)*(b - a + 1) == 2 * target) {
                res.push_back({a});
                for (int j = 1; j < (b - a + 1); j++) {
                    res[k].push_back(a + j);
                }
                k++;
                b++;
            } else if ((a + b)*(b - a + 1) < 2 * target) {
                b++;
            } else if ((a + b)*(b - a + 1) > 2 * target) {
                a++;
            }
        }
        return res;
    }
};