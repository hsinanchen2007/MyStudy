### 解题思路
关键是
for(j=0;j<256;j++)
        dp[0][j]=0;
dp的第一个状态其他的量要清零，不然变长数组无法初始化，会导致很多不确定值


### 代码

```c
int strStr(char * haystack, char * needle)
{
    if(needle==NULL||needle[0]=='\0')
    return 0;
    if(haystack==NULL)
    return -1;
	int LenStr=strlen(haystack);
	int LenSearch=strlen(needle);
    int dp[LenSearch][256];
    int i=0,j=0;
	int ch=0;
	int X=0;//shadow state
	//build the KMP array
    for(j=0;j<256;j++)
        dp[0][j]=0;
	dp[0][needle[0]]=1;
	for(j=1;j<LenSearch;j++)
	{
		for(ch=0;ch<256;ch++)
		{
			if(ch==needle[j])
			{
				dp[j][needle[j]]=j+1;
			}
			else
				dp[j][ch]=dp[X][ch];
		}
		X=dp[X][needle[j]];
	}
	for(i=0;i<LenStr;i++)
	{
		j=dp[j][haystack[i]];
		if(j==LenSearch)
        {
			return i-LenSearch+1;
        }
	} 
	return -1;
	
}
```