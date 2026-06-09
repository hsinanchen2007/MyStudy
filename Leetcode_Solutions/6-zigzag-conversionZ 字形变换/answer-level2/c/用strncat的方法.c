### 解题思路
      首先遍历字符串s每个字符s[i]，遍历的同时将s[i]以z型的方式分别连接到不同的字符串arr[j]后面，再把所有的字符串arr[j]，依次连接到待返回的一维字符串数组a，最后返回a。

方法： 用到memset函数给一维字符数组和二维字符数组初始化为0.
      用到strncat（arr[j],&s[i],1）从s[i]开始，连接1个字符（即将s[i]）到字符串arr[j]后面。
	  用到两个for循环与goto 语句，解决上下摆动的问题。
![1.png](https://pic.leetcode-cn.com/05995cf2de0270fca79896834de19d4b71192e05d8e58b7bf78034b4362c468d-1.png)


### 代码

```c

char * convert(char * s, int numRows)
{
	char arr[numRows][1000];
	int i=0,j=0,k=0;
	char *a;
	a=(char *)malloc(sizeof(char)*(strlen(s)+1));
	memset(a,0,strlen(s)+1);
    for(k=0;k<numRows;k++)
    {
        memset(arr[k],0,1000);
    }
    if(numRows==1) return s;
	RE: for(i;s[i]!=0;i++)
	{
		strncat(arr[j],&s[i],1);
		j++;
		if(j==numRows)//表示最后一排已经赋值
		{
			j-=2;
			i++;
			break; 
		} 
		
	}
	for(i;s[i]!=0;i++)
	{
		strncat(arr[j],&s[i],1);
		j--;
		if(j==-1)
		{
			j+=2;
			i++;
			goto RE;
		}
		
	}
	for(i=0;i<numRows;i++)
	{
		strcat(a,arr[i]);
	}
	return a;
}
```