### 解题思路
思路：本题和面试题10-I【[斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/c5xing-dai-ma-shuang-10000ni-yao-bu-yao-by-fan-hua/)】和面试题10-II【[青蛙跳台阶问题](https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/solution/c4xing-dai-ma-shuang-10000ni-yao-bu-yao-by-wangxia/)】思路一模一样。

本题有【递归】和【动态规划】两种解法，思路清晰，代码简单带注释，均5行解决。


### 代码

```cpp
class Solution {
public:
    int fib(int N) {
        //动态规划5行解决
        //声明n+1+1大小的vector（第一个+1是要存储0至n共n+1个数据；第二个+1是考虑n==0的情况，保证v[1]不越界）
        vector<int> v(N + 1 + 1, 0); 
        v[1] = 1;
        for(int i = 2; i <= N; i++)
            v[i] = (v[i - 1] + v[i - 2]) % 1000000007;//注意别忘记取余
        return v[N];//直接返回最后一个数，即最终结果

        //递归5行解决
        /*
        if(N == 0)
            return 0;
        if(N == 1)
            return 1;
        return fib(N - 1) + fib(N - 2);
        */
    }
};
```