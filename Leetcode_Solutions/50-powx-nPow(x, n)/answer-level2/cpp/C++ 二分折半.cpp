![pow.jpg](https://pic.leetcode-cn.com/bb7f5988b3c0f1fdde1ec1cd6deff35323a7d24b4d47a43cce471c502d9caec1-pow.jpg)


此方法用二进制来理解比较好，举例说明
x的21次方
21 二进制位10101
21 = 1 + 4 + 16
我们对21,循环右移一位（除以2）只要判断当前位为1，则将x的1次方，4次方，16次方,乘入结果
由于x每次移位都在平方,所以3次发现1的时候，其值分别为x,x4次方，x16次方，无需额外计算

循环右移使用/=2 而不是>>1,因为Leetcode不支持负数移位操作
```
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i & 1) res *= x;
            x *= x;
        }
        return n>=0?res:1/res;
    }
};
```
