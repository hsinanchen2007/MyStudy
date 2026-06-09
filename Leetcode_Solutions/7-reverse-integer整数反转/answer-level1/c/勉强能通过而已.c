### 解题思路
此处撰写解题思路

### 代码

```c
int reverse(int x)
{
	int max = 2e31 -1 ;
	int min = -1*2e31;
	int sign = 1;
	if(x < 0)sign = -1;
	x = fabs(x);
	if(x >= 0 && x <= 9)return x*sign;
	int *a = (int*)malloc(sizeof(int)*32);
	int i = 0;

	while(x != 0)
	{
		a[i++] = x%10;
		x /= 10;				
	}
	long result = a[i-1];
	long k=1;
	for(i -= 2;i>=0;i--)
	{
		k *= 10;
		result += a[i]*k;
		if(result*sign < min || result*sign >max)return 0;
	}
	
	return (int)result*sign;
}
```