### 解题思路
先对time数组取模，然后用一个hash表存储0-59每个元素出现的个数
再从右向左遍历，每次都从hash表中去除当前元素，这样表中的元素就都满足 j>i 了；
因为 （i + j）% 60 = ((i % 60) + (j % 60)) % 60;
所以需要对0单独考虑。

### 代码

```c
int numPairsDivisibleBy60(int* time, int timeSize){
	
	int count = 0;
	int store[60] = {0};//hash表
	
	for(int i = 0; i < timeSize; i++)
	{
		time[i] %= 60;
		store[time[i]]++;
	}
	
	for(int i = 0; i < timeSize - 1; i++)
	{
		store[time[i]]--;
		if(time[i] == 0)
		{
			count += store[time[i]];
		}
		else
		{
			count += store[60 - time[i]];
		}
	}
	
	return count;
}
```