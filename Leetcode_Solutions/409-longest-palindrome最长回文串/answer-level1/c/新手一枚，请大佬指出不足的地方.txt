### 解题思路
此处撰写解题思路

### 代码

```c
int longestPalindrome(char* s) {
	int hash[52];
	int n = strlen(s);
	int i,sum=0,j;
	bool flag = false;
	memset(hash, 0, sizeof(hash));
	for ( i = 0; i < n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			j = s[i] - 'a';
		else
			j = s[i] - 'A'+26;
		hash[j]++;
	}
	for (i = 0; i < 52; i++)
	{
	
		if (hash[i] % 2 == 0)
			sum += hash[i];
		else {
			sum = sum + (hash[i] - 1);
			flag = true;
		}
	}
	if (flag)
	{
		sum++;
	}
	return sum;
}
```