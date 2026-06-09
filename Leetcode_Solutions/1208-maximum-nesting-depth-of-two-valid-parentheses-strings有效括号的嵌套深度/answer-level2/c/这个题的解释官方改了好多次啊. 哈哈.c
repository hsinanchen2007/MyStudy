### 解题思路
此处撰写解题思路

### 代码

```c

int* maxDepthAfterSplit(char * seq, int* returnSize)
{
	int lenth = strlen(seq), flag = 0;
	int *ans = (int *)malloc(sizeof(int)*lenth);
	
	if(lenth)
	ans[0] = 0;
	for(int i = 1; i < lenth; i++)
	{
		if(seq[i] == seq[i-1])
		flag = 1-flag, ans[i] = flag;
		else
		ans[i] = flag;  
	} 
	
	*returnSize = lenth;
	return ans;
}
```