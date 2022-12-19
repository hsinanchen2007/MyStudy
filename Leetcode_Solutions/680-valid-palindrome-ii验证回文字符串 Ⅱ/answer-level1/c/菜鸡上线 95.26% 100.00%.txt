### 解题思路
![QQ图片20200318212337.png](https://pic.leetcode-cn.com/e11b0f927d62f5e095963c2abc2c9eb7ce6ce2d0f4602f9afa695cf870864191-QQ%E5%9B%BE%E7%89%8720200318212337.png)
双指针//碰到不一样两边各走一次
### 代码

```c
int haha(char*s,int t,int n)
{
	while(t<n)
	{
		if(s[t]==s[n])
		{
			t++;
			n--;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
bool validPalindrome(char * s)
{
	//双指针左右遍历
	int flag=0;//作为删除的标志
	int n=strlen(s)-1;
	int t=0;
	while(t<n)
	{
		if(s[t]==s[n])
		{
			t++;
			n--;
		}
		else 
		{
			break;
		}
	}
	if(haha(s,t+1,n))
	{
		return true;
	}
	else
	{
		if(haha(s,t,n-1))
		{
			return true;
		}
	}
	return false;
}

```