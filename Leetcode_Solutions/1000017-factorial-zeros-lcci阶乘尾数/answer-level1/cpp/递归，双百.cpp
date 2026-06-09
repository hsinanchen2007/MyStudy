# 基本思路
尾随零由数字5引起，因此算出从1到n有多少个5（包括分解出来的，如10=2*5）,即可确定n阶乘有多少个尾随零。

# 推导

n除以5，确定从1到n中，5的倍数的个数，假设有m个
5,10,15,20,25......，m*5

进行分解
1*5,2*5,3*5,4*5,5*5,...m*5
即
[1,2,3,4,5...m]*5

继续做下去，就是确定从1到m中，5的倍数的个数，跟前面是相似的问题，因此可以用递归来实现。


# 实现
```
class Solution {
public:
    int trailingZeroes(int n) 
    {
        int m = n/5;
        if(m==0)
            return 0;
        return  m + trailingZeroes(m);
    }
};
```
![捕获.PNG](https://pic.leetcode-cn.com/e13745035a6e2e4cf901c1f4e1c666892929b6d9b744fa9dab09b1fce31fa3f1-%E6%8D%95%E8%8E%B7.PNG)
