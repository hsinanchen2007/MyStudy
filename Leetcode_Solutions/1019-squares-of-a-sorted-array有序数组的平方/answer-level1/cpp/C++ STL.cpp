```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return a * a < b * b;
        });
        for_each(A.begin(), A.end(), [](auto& a) { a = a * a; });
        return A;
    }
};
```