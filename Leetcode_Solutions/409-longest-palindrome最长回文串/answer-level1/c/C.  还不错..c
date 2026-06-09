### 解题思路
继续加油.

### 代码

```c


int longestPalindrome(char * s)
{
	int statistics[127] = {0}, count = 0, max = 0;
	
	for( ; *s; s++)
	statistics[*s]++;
	
	for(int i = 65; i <= 122; i++)
	{
		if(statistics[i] % 2 != 0)
		if(max == 0)
		max = statistics[i];
		else
		count += statistics[i]-1; 
		
		else if(statistics[i] % 2 == 0)
		count += statistics[i]; 
	} 
	
	return count+max;
} 
```