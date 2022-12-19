### 解题思路

这题和前面一个求阶乘的题目一样，都是用到短路与的特性。

![乘法.PNG](https://pic.leetcode-cn.com/ada5e8059b3e030935cc007233bb5d2f82f9b5e22274accf88eec6fa181fae6d-%E4%B9%98%E6%B3%95.PNG)



### 代码

```c

static int sum;
int multiply(int A, int B)
{
    sum=0;
    B>1&&multiply(A,B-1);
    sum+=A;
    return sum;
}
```