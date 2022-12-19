![1.png](https://pic.leetcode-cn.com/d3572464043d249f6fb96e515d69944cbb88cf26e6d3afa582cf09d69e918cc6-1.png)

### 解题思路
本题看似简单，但是极易被绕晕
被绕了许久才找到正确答案。

映射map空间=citationsSize + 1；
如果引用次数>=citationsSize，map[citationsSize] ++；
亦如果引用次数>0，map[citations[i]] ++;

### 代码

```c
int hIndex(int* citations, int citationsSize){
	int *map = (int*)calloc(citationsSize + 1, sizeof(int));
	for (int i = 0; i < citationsSize; i++){
		if (citations[i]>=citationsSize)
			map[citationsSize] ++;
		else if (citations[i] > 0)
			map[citations[i]] ++;
	}
    if (map[citationsSize] == citationsSize)
		return citationsSize;
	for (int i = citationsSize - 1; i >=0 ; i--){
		map[i] += map[i + 1];
		if (map[i]>= i)
			return i;
	}
	return 0;
}
```