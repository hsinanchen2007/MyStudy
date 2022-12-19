### 解题思路
直线方程两点式与标准式、线性方程组中克拉默法则应用、C++函数重载

### 代码

```cpp
class Solution {
private:
    bool NumBetween (int a, int m, int n) {
        int small = min(m, n), large = max(m, n);
        return a  >= small &&  a <= large;
    }
    bool NumBetween (double a, int m, int n) {
        int small = min(m, n), large = max(m, n);
        return a  >= static_cast<double>(small) &&  a <= static_cast<double>(large);
    }
    bool PointBetween (vector<int> A, vector<int> M, vector<int> N) {
        return NumBetween(A[0], M[0], N[0]) && NumBetween(A[1], M[1], N[1]);
    }
    bool PointBetween (vector<double> A, vector<int> M, vector<int> N) {
        return NumBetween(A[0], M[0], N[0]) && NumBetween(A[1], M[1], N[1]);
    }
    vector<int> MinPoint(vector<int> M, vector<int> N) {
        if (M[0] < N[0] || (M[0] == N[0] && M[1] < N[1])) {
            return M;
        }
        else {
            return N;
        }
    }
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int A1 = end1[1] - start1[1], B1 = start1[0] - end1[0], C1 = start1[0] * end1[1] - end1[0] * start1[1];
        int A2 = end2[1] - start2[1], B2 = start2[0] - end2[0], C2 = start2[0] * end2[1] - end2[0] * start2[1];
        int d = A1 * B2 - A2 * B1, dx, dy;
        double x, y;
        vector<double> ans;
        if (d == 0) {
            if (A1 * start2[0] + B1 * start2[1] == C1) {
                vector<int> mp1 = MinPoint(start1, end1);
                vector<int> mp2 = MinPoint(start2, end2);
                if (PointBetween(mp1, start2, end2)) {
                    ans.push_back(static_cast<double>(mp1[0]));
                    ans.push_back(static_cast<double>(mp1[1]));
                }
                else if (PointBetween(mp2, start1, end1)) {
                    ans.push_back(static_cast<double>(mp2[0]));
                    ans.push_back(static_cast<double>(mp2[1]));
                }
            }
        }
        else {
            dx = C1 * B2 - C2 * B1;
            dy = A1 * C2 - A2 * C1;
            x = static_cast<double>(dx) / d;
            y = static_cast<double>(dy) / d;
            vector<double> tmp;
            tmp.push_back(x);  tmp.push_back(y);
            if (PointBetween(tmp, start1, end1) && PointBetween(tmp, start2, end2)) {
                ans = tmp;
            }
        }
        return ans;
    }
};
```