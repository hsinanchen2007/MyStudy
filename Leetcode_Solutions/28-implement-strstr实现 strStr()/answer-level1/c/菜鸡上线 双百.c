### 解题思路
![QQ图片20200410232113.png](https://pic.leetcode-cn.com/6a2529fea89900b8b3d1c3ae41223c46eb7f86c2510ab03554dcd81400a667c1-QQ%E5%9B%BE%E7%89%8720200410232113.png)
双百的暴力法

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
	int flag=0;//标志
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