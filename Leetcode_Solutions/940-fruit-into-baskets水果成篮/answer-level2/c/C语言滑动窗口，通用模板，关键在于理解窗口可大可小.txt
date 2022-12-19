
### 解题思路

滑动窗口，通用模板，关键在于理解滑动窗口的窗口可大可小
### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MAX_NODE   40002
static int hash[MAX_NODE];

int totalFruit(int *tree, int treeSize)
{
	int left = 0;
	int right = 0;
	int count = 0;
	int max = 0;
	int added[2];

	memset(hash, 0, sizeof(hash));
	if (!tree || treeSize == 0) {
		return 0;
	}
	for (right = 0; right < treeSize; right++) {
		hash[tree[right]]++;
		if (hash[tree[right]] == 1) {
			count++;
		}
		while(count > 2 && left < right) {
			hash[tree[left]]--;
			if (hash[tree[left]] == 0) {
				count--;
			}
			left++;
		}
		max = MAX(max, right - left + 1);
	}
	return max;
}
```