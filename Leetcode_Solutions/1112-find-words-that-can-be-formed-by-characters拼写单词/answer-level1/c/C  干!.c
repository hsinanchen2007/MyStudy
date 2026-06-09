哈哈, 这样都过了......


### 代码

```c


int countCharacters(char ** words, int wordsSize, char * chars)
{
	int count = 0, temp = 0;
	char a[127] = {0};
	
	for(int i = 0; chars[i]; i++)
	a[chars[i]]++;
	
	for(int i = 0; i < wordsSize; i++)
	{
		char b[127] = {0};
		for(int j = 0; words[i][j]; j++)
		b[words[i][j]]++;  
		
		temp = count;
		for(int k = 97; k <= 122; k++)
		{
			
			if(b[k])
			if(b[k] <= a[k])
			count += b[k]; 
			else
			{
				count = temp;
				break;
			}
		} 
	} 
	
	return count;
}
```