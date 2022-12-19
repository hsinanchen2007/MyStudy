### 解题思路
此处撰写解题思路

### 代码

```c
char * countAndSay(int n){

	char *last = (char*)malloc(sizeof(char) * 5000);
	char *now = (char*)malloc(sizeof(char) * 5000);
	char *mid;
	
	last[0] = '1';
	last[1] = '\0';
	now[0] = '1';
	now[1] = '\0';
	
	for (int k = 2; k <= n; ++k)
	{
		char temp = last[0];
		int count = 1, i = 1, j = 0,len = strlen(last);
		for (; i < len; ++i)
		{
			if (last[i] == temp)
				count++;
			else{
				now[j++] = count + '0';
				now[j++] = temp;
				temp = last[i];
				count = 1;
			}
		}
		now[j++] = count + '0';
		now[j++] = temp;
		
		now[j] = '\0';

		mid = last;
		last = now;
		now = mid;
	
	}
	
	return last;
}
```