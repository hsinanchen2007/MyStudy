```
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return {-1, -1};
        if (sum == 0) return {0, 2};
        int tailzeros = 0;
        int N = A.size();
        for (int i = N - 1; i >= 0 && A[i] == 0; --i) 
            ++tailzeros;
        int ones = 0;
        vector<int> v;
        string s;
        string t;
        for (int i = 0; i < N; ++i) {
            ones += A[i] == 1;
            if (!(t.empty() && A[i] == 0)) 
                t += A[i] + '0';
            if (ones == sum / 3) {
                for (int j = 0; j < tailzeros; ++j) {
                    ++i;
                    if (i >= N || A[i] == 1) 
                        return {-1, -1};
                    t += '0';
                }
                if (!s.empty() && s != t) 
                    return {-1, -1};
                s = t;
                t.clear();
                ones = 0;
                v.push_back(i);
            }
        }
        return {v[0], v[1] + 1};
    }
};
```

![image.png](https://pic.leetcode-cn.com/9202edf152b94372fa5d9213869abc145e1bffd5ff9cc2fe024fe8c3817f9aa6-image.png)
