```
class Solution {
public:
    inline vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto&& line : A) {
            reverse(line.begin(), line.end());
            for (auto&& num : line) {
                num = 1 - num;
            }
        }
        return A;
    }
};
```
