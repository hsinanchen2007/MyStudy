```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int distance = *std::max_element(A.cbegin(), A.cend()) - *std::min_element(A.cbegin(), A.cend());
        return distance <= 2*K ? 0 : distance - 2*K;
    }
};
```
