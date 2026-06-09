```
class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> m1;
        for (auto n : A) ++m1[n];
        unordered_map<int, int> m2;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ++m2[A[i] & A[j]];
            }
        }
        int res = 0;
        for (auto& p1 : m1) {
            for (auto & p2 : m2) {
                if ((p1.first & p2.first) == 0) {
                    res += p1.second * p2.second;
                }
            }
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/feb873bfb1229a879aac4a1b1f2a66e6074f288cfe5f3ceb61c692b456498fcb-image.png)
