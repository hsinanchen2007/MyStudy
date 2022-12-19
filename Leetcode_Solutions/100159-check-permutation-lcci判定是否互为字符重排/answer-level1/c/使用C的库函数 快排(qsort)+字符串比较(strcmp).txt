### 解题思路
1、先判断长度，如果长度不一致，则直接返回false
2、分别对2个字符串内的字符排序，再比较2个字符串是否相同

### 代码

```c
int cmp(const void *a, const void *b)
{
	return *(char*)a - *(char*)b;
}

bool CheckPermutation(char* s1, char* s2){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if(len1 != len2)
	{
		return 0;
	}
	qsort(s1, len1, sizeof(char), cmp);
	qsort(s2, len2, sizeof(char), cmp);
	if(strcmp(s1, s2) == 0)
	{
		return 1;
	}
	return 0;
}

```