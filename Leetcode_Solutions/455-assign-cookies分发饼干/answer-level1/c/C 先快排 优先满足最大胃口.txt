```
int compare(const void*, const void*);

int findContentChildren(int* g, int gSize, int* s, int sSize){
	
	qsort(g, gSize, sizeof(int), compare);
	qsort(s, sSize, sizeof(int), compare);
	
	int i = gSize - 1, j = sSize - 1, count = 0;
	
	while( i >= 0 && j >= 0)
	{
		if(s[j]>=g[i])
		{
			i--;
			j--;
			count++;
		}
		else
		{
			i--;
		}
	}
	
	return count;
	
}

int compare(const void* x, const void* y)
{
	return (*(int*)x - *(int*)y);
}
```
优先满足最大胃口和最小胃口是一样。

如果最大饼干大于最大胃口，直接把这块饼干给最大胃口，count++
    从饼干看，最大饼干可以满足任一胃口，所以无论满足哪一个都是一样的
    从胃口看，最大胃口最难被满足，所以优先满足最大胃口
否则最大胃口根本没办法满足，直接忽视