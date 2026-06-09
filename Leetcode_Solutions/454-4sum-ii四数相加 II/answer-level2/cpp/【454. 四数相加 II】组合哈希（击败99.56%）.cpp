## 思路
### 代码
```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> ab;
        int count = 0;
        for (int a : A) {
            for (int b : B) {
                ++ab[a + b];
            }
        }
        for (int c : C) {
            for (int d : D) {
                if (ab.count(-c-d) > 0) {
                    count += ab[-c-d];
                }
            }
        }
        return count;
    }
};
```
