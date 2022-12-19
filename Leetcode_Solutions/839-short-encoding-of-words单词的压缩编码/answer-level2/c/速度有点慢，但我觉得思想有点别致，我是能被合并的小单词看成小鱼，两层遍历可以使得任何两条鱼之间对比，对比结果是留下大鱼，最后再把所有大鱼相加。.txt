### 解题思路
此处撰写解题思路

### 代码

```c
int minimumLengthEncoding(char** words, int wordsSize) {
	int i = 0, j = 0, k = 0, cnt1 = 0, p = 1,m=0,n=0;
    int* a = (int*)malloc(sizeof(int) * wordsSize);
	for (int l = 0; l < wordsSize; l++)
	    a[l] = 1;
	while (i < wordsSize-1)
	{
        n=1;
        while(n<wordsSize-i)
        {
	     j = 0;
          k = 0;
	    	while (words[i][j] != '\0') j++;
	    	while (words[i+n][k] != '\0') k++;
	    	k--; j--;
		if (j < k) { m = j; p = 0;}
		else 
		{
			m = k; p = 1;
		}
		while (m >= 0)
		{
			if (words[i][j] != words[i + n][k])	
            break;
			j--; m--; k--;
		}
        
		if (m<0)
		{
			if (p == 0)a[i] = 0;
			else a[i + n] = 0;
		}
		p = -1; m = 0; 
        n++;
        }
        i++;
	}
	i = 0; j = 0;
	while (i < wordsSize)
	{
		if (a[i] == 1)
		{
			cnt1++; j = 0;
			while (words[i][j] != '\0') { cnt1++; j++; }
		}
		i++;
	}
	return cnt1;
}
```