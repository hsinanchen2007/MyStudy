### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

static char **ans;
static int ans_size;

static char zero_string[10] = { 0 };

void dfs(char *src, int src_index, char *dst, int dst_index, int step)
{
	int loop;
	char toint[4] = { 0 };

	//printf("dst %s\n", dst);
	if (step == 5) {
		if (src_index == strlen(src)) {
			ans[ans_size] = (char *)malloc(strlen(dst) + 1);
			memcpy(ans[ans_size], dst, strlen(dst));
			ans[ans_size][strlen(dst) - 1] = 0;
			//printf("%s\n", ans[ans_size]);
			ans_size++;
			return;
		} else {
			return;
		}
	}

	int len = strlen(src);

	for (loop = 1; ((loop <= 3) && (len - src_index - loop >= 0));
	     loop++) {
		if (loop > 1) {
			if (src[src_index] == '0')
				continue;
		}
		//printf("src index %d len %d loop %d ret %d\n", src_index, strlen(src), loop, strlen(src) - src_index - loop);
		memcpy(toint, src + src_index, loop);
		//printf("atoi %d step %d\n", atoi(toint), step);
		if (atoi(toint) <= 255) {
			memcpy(dst + dst_index, src + src_index, loop);
			dst[dst_index + loop] = '.';
			dfs(src, src_index + loop, dst, dst_index + loop + 1,
			    step + 1);
			memcpy(dst + dst_index, zero_string, loop + 1);
		}
	}
}

char **restoreIpAddresses(char *s, int *returnSize)
{
	int loop;
	ans_size = 0;
	char *tmp;

	if (!s) {
		*returnSize = 0;
		return ans;
	}
	ans = (char **)malloc(sizeof(char *) * MAX_SIZE);
	tmp = (char *)malloc(strlen(s) + 20);
	memset(tmp, 0, strlen(s) + 20);
	dfs(s, 0, tmp, 0, 1);
	*returnSize = ans_size;
	return ans;
}
```