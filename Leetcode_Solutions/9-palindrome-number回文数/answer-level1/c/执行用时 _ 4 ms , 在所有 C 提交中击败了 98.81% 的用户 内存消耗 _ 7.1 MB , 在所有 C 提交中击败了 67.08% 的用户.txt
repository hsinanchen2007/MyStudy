### 解题思路
此处撰写解题思路

### 代码

```c
bool isPalindrome(int x)
{
	if(x < 0)return false;
	if(x >= 0 && x <= 9)return true;

	long n = 0,m = x;
	int min = -1*2e31;
	int max = 2e31 - 1;
	while(m != 0)
	{
		n = n*10 + m%10;
		if(n > max || n < min)return false;
		m /= 10;
	}
	if(x == n)return true;
	else return false;
	
}
```