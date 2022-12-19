### 解题思路
只有借鉴......

### 代码

```c

int gcd(int a, int b)
{
	int c = 0;
	
	while(b)
	{
		c = a%b;
		a = b; 
		b = c;
	} 
	
	return a;
}


bool canMeasureWater(int x, int y, int z)
{
	if(x + y < z)
	return false;
	
	if(x == 0 || y == 0)
	return z == 0 || x+y == z;
	
	return z%gcd(x, y) == 0; 
}
```