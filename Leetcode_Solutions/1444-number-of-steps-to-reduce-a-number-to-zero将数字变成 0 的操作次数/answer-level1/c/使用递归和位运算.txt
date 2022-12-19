### 解题思路
1、使用递归来叠加次数；
2、使用位运算来计算除法；

### 代码

```c
int numberOfSteps (int num){
    if(num==0)
    {
        return 0;
    }else
    {
        if(num%2==0)
        {
            return numberOfSteps(num>>1)+1;
        }else
        {
            return numberOfSteps(num-1)+1;
        }
    }

}
```