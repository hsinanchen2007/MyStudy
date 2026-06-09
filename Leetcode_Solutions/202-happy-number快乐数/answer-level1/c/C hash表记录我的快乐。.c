### 解题思路
有一个快乐数重复出现，即是进入循环了。
用hash表记录出现过的快乐数。
一个有 i 位 的数 n 的各位平方和  <= i * 81
而 n 是大于等于 10^(i - 1)。 
i 小于等于 3 时，两者才出现交集，
n < 3 * 81 = 243时，一个数的各位平方和才有可能等于自身，才有快乐数循环的可能。
因此hash表的长度只需要有243就可以了。

### 代码

```c
bool isHappyCore(int n, int* map);

bool isHappy(int n){
	
	int map[243] = {0};
	return isHappyCore(n, map);
}

bool isHappyCore(int n, int* map)
{
	if(n == 1) 
	{
		return true;
	}
	
	if(n <= 243) // 小于等于243
	{
		if(map[n - 1] == 1)
		{
			return false;
		}
		else
		{
			map[n - 1] = 1;
		}
	}
	
	int next = 0;
	
	while(n > 0)
	{
		next += (n % 10) * (n % 10);
		n /= 10;
	}
	
	return isHappyCore(next, map);
}
```