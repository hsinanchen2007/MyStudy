### 解题思路
有没知情人士解答下。

### 代码

```cpp
class Solution
{
   public:
    int sumSubarrayMins(vector<int>& A)
    {
        const long M = 1e9 + 7;
        int len = A.size();
        if (len == 0) {
            return 0;
        }
        stack<int> s;
        vector<long> sum(len, 0);
        sum[0] = A[0];
        s.push(0);
        long ans = sum[0];
        for (int i = 1; i < len; i++) {
            int curr = s.top();
            if (A[i] > A[curr]) {
                sum[i] = sum[i - 1] + A[i];
            } else {
                while (s.empty() == false && A[s.top()] > A[i]) {
                    s.pop();
                }
                if (s.empty() == true) {
                    sum[i] = (i + 1) * A[i];
                } else {
                    int k = s.top();
                    sum[i] = sum[k] + (i - k) * A[i];
                }
            }
            ans += sum[i] % M;
            ans = ans % M;
            s.push(i);
        }
        return ans;
    }
};

```