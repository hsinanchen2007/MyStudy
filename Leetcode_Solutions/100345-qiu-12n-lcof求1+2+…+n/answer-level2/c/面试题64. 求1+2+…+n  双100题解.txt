#

题目描述挺唬人的，其实代码还是挺简单的，主体思路使用递归去完成累加和，利用C语言短路与的特点，实现递归的终止。

由于不让用if，所以用了位运算实现了对sum的清零。

![1585277380(1).png](https://pic.leetcode-cn.com/afb23da790fbdc6a8a9a04454fce17364dd7cfbbad05f575edc788b387041c4c-1585277380\(1\).png)


### 代码

```c
static int sum;

int sumNums(int n)
{   
    sum=((sum!=0)&(sum==0));
    n>0&&sumNums(n-1);
    sum+=n;
    return sum; 
}
```