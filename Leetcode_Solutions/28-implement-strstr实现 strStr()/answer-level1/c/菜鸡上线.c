### 解题思路
![QQ图片20200321112513.png](https://pic.leetcode-cn.com/077bd198dec97fb60b194faa42bfbffbd035c28ec79fccd7cdaff67d3b93b056-QQ%E5%9B%BE%E7%89%8720200321112513.png)

暴力破解

### 代码

```c
int strStr(char * haystack, char * needle)
{
	int n=strlen(haystack);
	int m=strlen(needle);
	if(m==0)
	{
		return 0;
	}
	int i=0;
	int t=0;
	for(i=0;i<n;)
	{
		if(haystack[i]==needle[t])
		{
			t++;
			i++;
			if(t==m)
			{
				return i-t;
			}
		}
		else
		{
			if(t!=0)
			{
            i=i-t;
			t=0;
				
			}
			i++;
		}
	}
	return -1;
}

```