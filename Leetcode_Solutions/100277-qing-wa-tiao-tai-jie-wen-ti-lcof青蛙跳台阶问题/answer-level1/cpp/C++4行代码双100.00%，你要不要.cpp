### 解题思路
![image.png](https://pic.leetcode-cn.com/48e1bc4135196823af64a5c774fc5cbd180c9a00b344f5b51d3fcd34c237f079-image.png)
思路：本题和面试题10-I【斐波那契数列】思路一模一样，传送门【[C++5行代码双100.00%，你要不要](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/c5xing-dai-ma-shuang-10000ni-yao-bu-yao-by-fan-hua/)】

本题常见思路有【递归】和【动态规划】两种。但递归在给的测试样例中不通过，超出了时间限制(执行43时就超出了，n最大可以达到100)，所以考虑动态规划。
![image.png](https://pic.leetcode-cn.com/893c75d25c37612a99aa8b1f823266f0ebe9e72d749ade8f24ca16c39673c570-image.png)

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        //动态规划4行解决
        //声明n+1大小的vector，+1是要存储0至n共n+1个数据。
        vector<int> v(n + 1, 1); 
        for(int i = 2; i <= n; i++)
            v[i] = (v[i - 1] + v[i - 2]) % 1000000007;//注意别忘记取余
        return v[n];//直接返回最后一个数，即最终结果
    }
};

/*
//另附3行递归代码
class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1)
            return 1;
        return numWays(n-1) + numWays(n-2);
    }
};
*/
```