![1.png](https://pic.leetcode-cn.com/c2ccc83457256932859f19e37dd8abee003631ef8ed48314d9e2960c39be7b8f-1.png)

### 解题思路
1、先把C出现的位置依次放入map中，map就是一个升序数组
2、遍历S，如果相等，map对应的指针+1；不相等，则取map[j] - i 和 i - map[j - 1]的较小数。
不会画图，画个图就简单明了

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * S, char C, int* returnSize){
	int *map = (int*)calloc(500, sizeof(int)), len = strlen(S), j = 0;
	for (int i = 0; i < len; i++)
		if (S[i] == C)
			map[j++] = i;
	int *res = (int*)calloc(len, sizeof(int));
	j = 0;
	for (int i = 0; i < len; i++){
		if (S[i] == C){
			res[i] = 0;
			j++;
		}
		else{
			if (0 == j)
				res[i] = map[j] - i;
			else{
				if (0 == map[j])
					res[i] = i - map[j - 1];
				else
					res[i] = map[j] - i < i - map[j - 1] ? map[j] - i : i - map[j - 1];
            }
		}
	}
	*returnSize = len;
	return res;
}
```