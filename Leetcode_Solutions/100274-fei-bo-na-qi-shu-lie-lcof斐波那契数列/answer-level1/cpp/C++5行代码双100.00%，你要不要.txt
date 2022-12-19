### 解题思路
![image.png](https://pic.leetcode-cn.com/b49301932401822bf240c3eba8e6bf02d638adcb34a714ff070cde12e2f6739b-image.png)
思路：本题常见思路有【递归】和【动态规划】两种。但递归在给的测试样例中不通过，超出了时间限制(执行43时就超出了，n最大可以达到100)，所以考虑动态规划。
![image.png](https://pic.leetcode-cn.com/ee5bf3989f7190f0939896b66bd6b4aba107fdc0e4345d8aa229e389057025c2-image.png)

思路清晰，代码简单带注释。

### 代码

```cpp
class Solution {
public:
    int fib(int n) {
        //动态规划5行解决
        //声明n+1+1大小的vector（第一个+1是要存储0至n共n+1个数据；第二个+1是考虑n==0的情况，保证v[1]不越界）
        vector<int> v(n + 1 + 1, 0); 
        v[1] = 1;
        for(int i = 2; i <= n; i++)
            v[i] = (v[i - 1] + v[i - 2]) % 1000000007;//注意别忘记取余
        return v[n];//直接返回最后一个数，即最终结果
    }
};

/*
//另附递归代码，测试不通过。
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
};
*/
```