### 解题思路
遍历序列seq，模拟动态添加A，B序列
1）用a，b分别记录A，B序列当前状态
2）添加'('时状态+1，添加')'时状态-1，由此可以看出a、b状态值即为当前已派分序列的实时depth层数
3）为保证max(A,B)最小，派分时只需维护max(a, b)每次最小，同时记录对应的res值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
	*returnSize = len;
	int *res = (int*)malloc(sizeof(int) * len);
	// 模拟派分 A序列对应a-0,B序列对应b-1   '(' +1, ')' -1
	int a = 0;
	int b = 0;
	for (int i = 0; i < len; i++) {
		if (seq[i] == '(') {
			// 按优先级排序
			if (a == 0) {
				a++;
				res[i] = 0;
			} else if (b == 0) {
				b++;
				res[i] = 1;
			} else if (a < b) {
				a++;
				res[i] = 0;
			} else if (a >= b) {
				b++;
				res[i] = 1;
			}
		} else {
			if (a > b) {
				a--;
				res[i] = 0;
			} else {
				b--;
				res[i] = 1;
			}
		}
	}
	return res;
}
```