1. 解法 1

使用二项定理[二项式系数 - 维基百科，自由的百科全书](https://zh.wikipedia.org/wiki/%E4%BA%8C%E9%A0%85%E5%BC%8F%E4%BF%82%E6%95%B8)
- 阶乘公式
![](https://pic.leetcode-cn.com/8c2d41dd6f25b1210812152338dbeb82f7bd569f61415fa9b805d2d2c181f208-file_1565055811040)
- 递归公式
![](https://pic.leetcode-cn.com/c28cf0f606013884c0b6ca47c53a6cf87d822965dca8e14afb0a0032b1c11c14-file_1565055811046)
- 乘数公式
![](https://pic.leetcode-cn.com/21b0beafe966eeff25436844838bf3c907f33480f3c845c6040a8271e923bacc-file_1565055811048)

```cpp
class Solution {
public:
    // int combination(int m, int n)
    // {
    //     if (m == 0 || n == 0)
    //         return 1;
    //     if (n > m / 2)
    //         return combination(m, m - n);
    //     // 排列组合的计算方法
    //     return combination(m - 1, n - 1) + combination(m - 1, n);
    // }

    // 化简
    int combination(int m, int n)
    {
        double ret = 1.0, k = min(n, m - n);
        for (int i = 1; i <= k; i++) {
            ret *= m - i + 1;
            ret /= i;
        }
        return (int)ret;
    }

    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        vector<vector<int>> ret(numRows);
        for (int it = 0; it < numRows; it++) {
            for (int j = 0; j <= it; j++) {
                ret[it].push_back(combination(it, j));
            }
        }
        return ret;
    }
};
```

2. 解法 2

使用模拟构造（动态规划）

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0)
            return {};
        vector<vector<int>> ret(numRows);
        for (int it = 0; it < numRows; it++) {
            for (int j = 0; j <= it; j++) {
                // 初始值和两侧的值衡为1
                if (it < 1 || j == 0 || j == it)
                    ret[it].push_back(1);
                else {
                    int item = ret[it - 1][j - 1] + ret[it - 1][j]; 
                    ret[it].push_back(item);
                }
            }
        }
        return ret;
    }
};
```