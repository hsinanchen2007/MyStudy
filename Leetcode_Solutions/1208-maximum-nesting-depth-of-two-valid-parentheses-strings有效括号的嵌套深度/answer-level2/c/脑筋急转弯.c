### 解题思路
这题有点推理或者脑筋急转弯
设单个字符串的最大深度为n，现在分成a,b 2个部分
则a和b的最大深度为n/2的时候，a b合到一起一定是最优解
因此，第一遍求最大深度max，第二遍便利当前深度a小于max的时候放到a，其他的放到b

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
这题有点推理或者脑筋急转弯
设单个字符串的最大深度为n，现在分成a,b 2个部分
则a和b的最大深度为n/2的时候，a b合到一起一定是最优解
因此，第一遍求最大深度max，第二遍便利当前深度a小于max的时候放到a，其他的放到b
*/

#define MAX_NODE  10002
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

static int ans[MAX_NODE];

int get_max_depth(char *data)
{
	int i;
	int depth = 0;
	int max = INT_MIN;

	for (i = 0; i < strlen(data); i++) {
		if (data[i] == '(') {
			depth++;
			max = MAX(max, depth);
		} else {
			depth--;
		}
	}
	return max;
}

int *maxDepthAfterSplit(char *seq, int *returnSize)
{
	int max;
	int i;
	int a_depth = 0;

	if (!seq || strlen(seq) > MAX_NODE) {
		*returnSize = 0;
		return ans;
	}
	max = get_max_depth(seq);
	//printf("max depth %d\n", max);
	for (i = 0; i < strlen(seq); i++) {
		if (seq[i] == '(') {
			if (a_depth < max / 2) {
				a_depth++;
				ans[i] = 0;
			} else {
				ans[i] = 1;
			}
		} else {
			if (a_depth > 0) {
				a_depth--;
				ans[i] = 0;
			} else {
				ans[i] = 1;
			}
		}
	}
	*returnSize = strlen(seq);
	return ans;
}
```