# 思路：
1，利用单调栈记录截止到当前下标之前的所有下边界
2，利用`sums[i]`记录所有以`i`为终点的区间最小值之和
```C++ []
class Solution {
public:
    const long M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        int N = A.size();
        stack<int> st;
        vector<long> sums(N, 0);
        for (int i = 0; i < N; ++i) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if (st.empty()) {
                sums[i] = A[i] * (i + 1);
            } else {
                sums[i] = sums[st.top()] + A[i] * (i - st.top());
            }
            sums[i] %= M;
            st.push(i);
        }
        long res = 0;
        for (auto x : sums) {
            res += x;
            res %= M;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5226c32ae203a7f595d96329d51a7e1601a1354c50e3258281250c4011b3b57f-image.png)
