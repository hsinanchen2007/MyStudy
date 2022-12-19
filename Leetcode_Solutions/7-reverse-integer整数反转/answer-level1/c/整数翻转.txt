### 解题思路
先把x转换成long再操作
输出前和 MAX_INT、MIN_INT 作比较

MAX_INT=(int)(((unsigned)(~0))>>1);
MIN_INT=(int)(((unsigned)1)<<(sizeof(int)*8-1)|1)

### 代码

```c
int reverse(int x){
	long result = 0,temp=(long)x;
	int flag = 0;
	if (temp< 0)
	{
		flag = 1;
		temp *= -1;
	}
	while (temp != 0)
	{
		result = result * 10 + temp % 10;
		temp /= 10;
	}
    result=flag?result*(-1):result;
    
	int MAXint = (int)((unsigned)(~0) >> 1);
	int MINint = (int)(((unsigned)1) << (sizeof(int) * 8 - 1) | 1);
	if (MINint <= result && result <= MAXint)
		return (int)result;
	else
		return 0;
}
```