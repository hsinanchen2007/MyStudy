```c++
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            reverse(row.begin(), row.end());
            for_each(row.begin(), row.end(), [](auto& e) { e = !e; });
        }
        return A;
    }
};
```