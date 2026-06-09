### 解题思路
X乘2，相当于Y除以2
X加一，相当于Y减1
情况一：X大于Y时，需要X-Y步结束
情况二：X小于Y，Y为偶数时，Y除以2即可，count++
情况三：X小于Y，Y为奇数时，Y减1，count++
### 代码

```c
int brokenCalc(int X, int Y){
    int count=0;
    while(X<Y)
    {
        count++;
        if(Y%2==1)
        {
            Y++;
        }
        else
        {
            Y=Y>>1;
        }
    }
    return X-Y+count;

}
```