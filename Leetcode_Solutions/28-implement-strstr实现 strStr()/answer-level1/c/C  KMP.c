### 解题思路
此处撰写解题思路
哎，几经崩溃，耗时两天才写出来。了解KMP算法花了半天，然后中间思路没有理通，第二天才搞懂。
加上力扣内存溢出检测挺严的，我的next一开始溢出了，后来才找到。
耗时比较长64ms，一会看看暴力算法能用多长时间。
### 代码

```c
void getNext(char *needle, int *next)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < strlen(needle))
	{
		if (j == -1 || needle[i] == needle[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int strStr(char * haystack, char * needle) {
	int n_len = strlen(needle);
	int h_len = strlen(haystack);
	int *next = (int*)malloc(sizeof(int)*(n_len+1));
	getNext(needle, next);
	int Index_needle = 0, Index_haystack = 0;
	if (n_len == 0)
		return 0;
    if (h_len == 0)
		return -1;
	for (;Index_haystack < h_len;)
	{
		for (;Index_needle < n_len&&Index_needle != -1;)
		{
			if (haystack[Index_haystack] == needle[Index_needle])
			{
				Index_haystack++;
				Index_needle++;
			}
			else
			{
				Index_needle = next[Index_needle];
			}
		}
		if (Index_needle == n_len)//字串遍历完也就是找到 
		{
			free(next);
			return Index_haystack - n_len;
		}
		if (Index_needle == -1)
		{
			Index_haystack++;
			Index_needle = 0;
		}
	}
	free(next);
	if (Index_needle == n_len)
		return Index_haystack - n_len;
	else
		return -1;
}


```