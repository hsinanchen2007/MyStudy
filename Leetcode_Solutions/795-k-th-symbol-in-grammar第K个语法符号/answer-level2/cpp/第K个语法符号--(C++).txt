### 解题思路
解法：思路很重要，刚开始我首先想到了自上而下dp，结果超时（代码也会放到下面以供参考）。然后发现规律第4行第6个数字是由第3行第3个数字变来的，第3行第3个数字是由第2行第1个数字变来的（这里会发现奇偶不同，第3行第3,4个数字都由第2行第1个数字变来）。
找出规律，设array[N][K]为第N行第K个数字，其实就是函数kthGrammar(int N, int K)

dp数组形式
K为偶数时, array[N][K] = array[N-1][K/2] == 0 ? 1 : 0    (注意：k从1开始，不是0)
K为奇数时, array[N][K] = array[N-1][(K+1)/2] == 0 ? 0 : 1

递归函数形式
K为偶数时, kthGrammar(N, K) = kthGrammar(N-1, K/2) == 0 ? 1 : 0    (注意：k从1开始，不是0)  
=> `return kthGrammar(N-1, K/2) == 0 ? 1 : 0;`
K为奇数时, kthGrammar(N, K) = kthGrammar(N-1, (K+1)/2) == 0 ? 0 : 1
=> `return kthGrammar(N-1, (K+1)/2);`
### 代码

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        // 找规律
        // 第N行由N-1行的0,1变来的,
        // K为偶数时, array[N][K] = array[N-1][K/2] == 0 ? 1 : 0    (注意：k从1开始，不是0)
        // K为奇数时, array[N][K] = array[N-1][(K+1)/2] == 0 ? 0 : 1
        if (N == 1)
            return 0;
        if (K % 2 == 0) {
            // 偶数
            return kthGrammar(N-1, K/2) == 0 ? 1 : 0;
        }
        else 
            return kthGrammar(N-1, (K+1)/2) == 0 ? 0 : 1;
    }
};
```

超时解法：dp计算出所有值

###代码

```
class Solution {
public:
    int kthGrammar(int N, int K) {
        // 一看就是自上而下dp
        vector<vector<int> > dp;
        dp.push_back(vector<int>(1, 0));
        for (int i = 1; i < N; i++) {
            vector<int> item;
            for (int j = 0; j < dp[i-1].size(); j++) {
                if (dp[i-1][j] == 0) {
                    item.push_back(0);
                    item.push_back(1);
                }
                else {
                    item.push_back(1);
                    item.push_back(0);
                }
            }
            dp.push_back(item);
        }

        return dp[N-1][K-1];
    }
};
```
