### 解题思路
每操作一次就记一次数

### 代码

```c
int numberOfSteps (int num){
    int count = 0;
	while (num != 0)
	{
		if (num % 2)
		{
			num = num - 1;
			count++;
		}
		else
		{
			num = num/2;
			count++;
		}
	}
    return count;
}
```