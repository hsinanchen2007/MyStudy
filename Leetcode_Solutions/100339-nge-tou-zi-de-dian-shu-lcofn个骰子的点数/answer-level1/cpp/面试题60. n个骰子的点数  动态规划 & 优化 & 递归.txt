```cpp

// 1. 动态规划 二维填表
class Solution {
private:
    vector<vector<int>> memo;
    vector<double> res;

public:
    vector<double> twoSum(int n) {
        memo = vector<vector<int>>(n + 1, vector<int>(6*n + 1, 0 ));
        for (int k = 1; k <= 6; k++)
            memo[1][k] = 1;
        
        for (int i = 2; i <= n; i++) 
            for (int k = i; k <= 6*i; k++) {
                int t = k - 1;
                while (t >= i - 1 && t >= k - 6)
                    memo[i][k] += memo[i-1][t--];
            }
        
        double fenmu = pow(6, n);
        vector<int> tmp (memo[n].begin() + n, memo[n].begin() + 6 * n + 1);
        for (auto x : tmp)
            res.push_back(double(x)/fenmu);
        return res;
    }
};


// // 1.1 动态规划 优化存储
// class Solution {
// private:
//     vector<vector<int>> memo;
//     vector<double> res;

// public:
//     vector<double> twoSum(int n) {
//         memo = vector<vector<int>>(2, vector<int>(6 * n + 1, 0 ));
//         for (int k = 1; k <= 6; k++)
//             memo[1][k] = 1;
        
//         for (int i = 2; i <= n; i++) 
//             for (int k = i; k <= 6*i; k++) {
//                 int t = k - 1;
//                 memo[i%2][k] = 0;
//                 while (t >= i - 1 && t >= k - 6)
//                     memo[i%2][k] += memo[(i+1)%2][t--];
//             }
        
//         double fenmu = pow(6, n);
//         vector<int> tmp (memo[n%2].begin() + n, memo[n%2].begin() + 6 * n + 1);
//         for (auto x : tmp)
//             res.push_back(double(x)/fenmu);
//         return res;
//     }
// };




// // 2. 递归超时
// class Solution {
// private:
//     vector<double> res;

//     // n个骰子，已经处理了index个骰子的和，和为sum
//     void prob(const int n, int index, int sum) {
//         if (index == n) {
//             res[sum - n] ++;
//             return;
//         }
//         for (int i = 1; i <= 6; i++) {
//             prob(n, index + 1, sum + i);
//         }
//     }

// public:
//     vector<double> twoSum(int n) {  // n个骰子，点数和的概率分布
//         res = vector<double>(6 * n - n + 1, 0);
//         double fenmu = pow(6, n);
//         prob(n, 0, 0);
//         for (auto &x : res)
//             x /= fenmu;
//         return res;
//     }
// };
```