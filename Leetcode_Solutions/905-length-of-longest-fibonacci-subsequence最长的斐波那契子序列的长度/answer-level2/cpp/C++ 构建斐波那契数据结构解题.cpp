思路比较简单，代码如下：
```
class Solution {
public:
    struct Fib {
        int count;
        int f0;
        int fi;
        int fii;
        Fib(int _f0, int _f1) : count(2), f0(_f0), fi(_f0), fii(_f1) {}
        int next() {
            return fi + fii;
        }
        void step() {
            ++count;
            int t = fii;
            fii = fi + fii;
            fi = t;
        }
    };
    vector<bool> F;
    int lenLongestFibSubseq(vector<int>& A) {
        if (A.size() < 3) return 0;
        int M = *max_element(A.begin(), A.end());
        F = vector<bool>(M + 1, false);
        for (auto n : A) F[n] = true;
        int res = 0;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                Fib f = Fib(A[i], A[j]);
                while (f.next() <= M && F[f.next()]) f.step();
                res = max(res, f.count);
            }
        }
        return (res > 2) ? res : 0;
    }
};
```
