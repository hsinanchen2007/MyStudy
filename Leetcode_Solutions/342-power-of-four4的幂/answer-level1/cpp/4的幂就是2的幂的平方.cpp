判断一个数是不是4的幂，就看他是不是2的幂的平方
根据题目231
判断一个数是不是2的幂的平方：n&(n-1)==0 
对传入的参数num分情况讨论
1) num<=0 返回false
2) num>0 开方判断m=sqrt(num)是否是2的幂，注意还要加上约束条件m*m==num
代码：
```
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
        int n=sqrt(num);
        return (n*n==num)&&((n&(n-1))==0);
    }
};
```

