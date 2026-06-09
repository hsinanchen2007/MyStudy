### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:

    //递归  大量的重复计算
    int fib(int N) 
    {
        if (N <= 1)
        {
            return N;
        }

        return fib(N - 1) + fib(N - 2);
    }


    //动态规划 空间复杂度O(N)
    int fib(int N)
    {
        if (N <= 1)
        {
            return N;
        }

        vector<int> v(N + 1);
        v.at(0) = 0; //F(0)
        v.at(1) = 1; //F(1)

        for (int i = 2; i <= N; ++i)
        {
            v.at(i) = v.at(i - 1) + v.at(i - 2);
        }

        return v.back();
    }


    //动态规划 空间复杂度O(1)
    int fib(int N)
    {
        if (N <= 1)
        {
            return N;
        }

        int dp0 = 0;
        int dp1 = 1;
        int dp2 = 1;

        for (int i = 2; i < N; ++i)
        {
            int tmp = dp2 + dp1;
            dp0 = dp1;
            dp1 = dp2;
            dp2 = tmp;
        }

        return dp2;
    }
};
```