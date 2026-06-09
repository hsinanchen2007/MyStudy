### 解题思路
numRows = 4时；
P     I     N
A   L S   I G
Y A   H R 
P     I
用下标来表示
PAYPALISHIRING
01232101232101
使用一个temp数组做下标，标记Z字形的字母的下标，分为0行，1行，2行，3行分别输出；办法比较笨，但是比较好理解。看了别人的解法，感觉很汗颜，没看懂别人的。

### 代码

```c
char * convert(char * s, int numRows){
    if(numRows <= 1){
        return s;
    }
    int nLen = strlen(s);
    int *ntemp = (int *)malloc(sizeof(int)*(nLen));
    char *newstr = (char *)malloc(sizeof(char) *(nLen+1));
    int i = 0, j = 0, x = 0;
    int naddflag = 0;
    int nsubflag = 0;
    while(s[i] != '\0'){
    	if(x == numRows -1)
    	{
    		naddflag = 0;
    		nsubflag = 1;
    	}
    	else if(x == 0)
    	{
    		nsubflag = 0;
    		naddflag = 1;
    	}
    	ntemp[i] = x;
    	if(naddflag == 1)
    	{
    		x++;
    	}
    	else
    	{
    		x--;
    	}
    	i++;
    }
    i = 0;
    x = 0;
    for(; i < numRows; i++)
    {
    	for(int j = 0; j< nLen; j++)
    	{
    		if(ntemp[j] == i)
    		{
    			newstr[x] = s[j];
    			x ++;
    		}
    	}
    }
    newstr[nLen] = '\0';
    free(ntemp);
    return newstr;
}
```