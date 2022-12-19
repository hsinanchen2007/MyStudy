有没有其他办法啊，这个感觉好搓

```
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> abSum;
        for (auto a : A) {
            for (auto b : B) {
                int sum = a+b;
                if (abSum.find(sum) != abSum.end()) {
                    abSum[sum] = abSum[sum] + 1;
                } else {
                    abSum[sum] = 1;
                }
            }
        }
        int res = 0;
        for (auto c : C) {
            for (auto d : D) { 
                int cd = -(c + d);
                if (abSum.find(cd) != abSum.end()) {
                    res += abSum[cd];
                }
            }
        }
        return res;
    }
};
```