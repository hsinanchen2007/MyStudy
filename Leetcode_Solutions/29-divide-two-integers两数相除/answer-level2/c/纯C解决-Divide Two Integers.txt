### 解题思路
这道题给medium.....我实在是觉得小看了吧.....整整做了五天，自己都感动了自己。


### 代码

```c
int opposite(int key)//补码转换
{
    return ~key+1;
}
int divide(int dividend, int divisor){
    int mark=1;

    if(dividend>0)//转成负数
    {
        dividend=opposite(dividend);
        mark=opposite(mark);
    }
    if(divisor>0)
    {
        divisor=opposite(divisor);
        mark=opposite(mark);
    }

    int quotient=0;
    int base=divisor;
    int num=1;
    printf("the base is :%d",base);
    while(dividend<=base)
    {
        quotient-=num;
        dividend-=base;
        if(dividend<=base)
        base+=divisor;
        num++;
    }
    printf("the base is:%d\n",base);
    printf("the quotient is:%d\n",quotient);
    while(dividend<=divisor)
    {
        quotient--;
        dividend-=divisor;
    }
    if(quotient == INT_MIN){
			if( mark > 0){
				return INT_MAX;
			}else{
				return INT_MIN;
			}
		}else{
			if(mark > 0){
				return opposite(quotient);
			}else{
				return quotient;
			}
		}
    return mark>0?quotient:-quotient;
}
```