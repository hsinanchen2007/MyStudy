### 解题思路

我的办法比较笨：
1、先按照引用数从多到少排序；
2、然后便利引用数数组，当出现引用数<=下标时，说明hindex出现了。
3、到底是引用数作为hindex，还是下标作为hindex，需要比较一下大小。

### 代码

```c
int compar(const void *p1, const void *p2){
	return *(int*)p2 - *(int*)p1;
}

int hIndex(int* citations, int citationsSize){
	if (citationsSize == 0){
		return 0;
	}
	qsort(citations,citationsSize,sizeof(int),compar);

	for (int i = 0; i < citationsSize; ++i) {
		if(citations[i] == 0){
			return i;
		}
		if(citations[i]<=i+1){
			return (citations[i]>i)?citations[i]:i;
		}
	}
	return citationsSize;
}
```