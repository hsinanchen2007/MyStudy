依题意可得
$f[i] - f[i-1] = \sum^{i != n - i}_{i=0}{A[i]} - (n - 1) \times A[n-i]$
化简得递推公式
$f[i] = f[i-1] - n \times A[n-i] + \sum^{n}_{i=0}{A[i]}$
很明显，先求数组A的和，然后根据公式计算就可以了
```
class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        int n = A.size();
        long long res = 0, f = 0, sigmaA = 0, halfp;
        for (int i = 0; i < n; i++) {
            res += i * A[i];
            sigmaA += static_cast<long long>(A[i]);
        }
        f = res;
        for (int i = 1; i < n; i++) {
            halfp = (n / 2) * A[n - i]; //数据太大，直接乘会出界，分两次减
            f += sigmaA - halfp - halfp - (n % 2 == 0 ? 0 : A[n - i]);
            res = max(res, f);
        }
        return res;
    }
};
```
