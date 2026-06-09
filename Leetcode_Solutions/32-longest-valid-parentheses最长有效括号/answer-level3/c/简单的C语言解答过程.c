### 简单的C语言解答过程
首先，正序遍历整个序列，并记录其中有效括号序列的最大长度。

但是，需要注意的是，出现结尾是...()()()()(()这种情况的序列；这种结尾是无效括号序列中，可能会包含最长有效括号序列。
因此，加了一个当count!=0时来处理它，并且是从代码中你会发现是从后至前来判断有效括号的。
最后要注意的是：在整个代码结束还加了这个：res = res>len?res:len;是因为判断结束，正好count==0时，这一次的len是没有进行这个操作的，所以必须要在最后加上这个
![image.png](https://pic.leetcode-cn.com/026ec720e63d895693ff3a65bff9d03ed80e49125787da8e136af4aafaa7c28e-image.png)

### 代码

```c
int longestValidParentheses(char * s){
	int count = 0,len = 0,res = 0;
	int LS = strlen(s);
	for(int i=0;i<LS;i++)
	{
		if(s[i]=='(')   count++;
		if(s[i]==')')
		{
			if(count>0)
			{
				count--;
				len +=2;
			}  
			else
			{
				res = res>len?res:len;
				count = 0;
				len = 0;
			}
		} 
	}
	if(count!=0)
	{
		int low = LS-count-len;
		count = 0;
		len = 0;
		for(int i=LS-1;i>=low;i--)
		{
			if(s[i]==')')  count++;
		    if(s[i]=='(')
		    {
		    	if(count>0)
		    	{
		    		count--;
		    		len+=2;
		    	}
		    	else
		    	{
		    		res = res>len?res:len;
					count = 0;
					len = 0;	
		    	}
		    }
		}
	}
	res = res>len?res:len;
	return res;
}
```