### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxConsecutiveOnes(int *nums, int numsSize)
{
	int i;
	int j;
	int max = 0;
	int used = 0;
	j = 0;
	if (!nums || numsSize == 0) {
		return 0;
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] == 1) {
			;
		} else {
			used++;
			if (used > 1) {
				while (j < i) {
					if (nums[j] == 0) {
						used--;
					}
					j++;
					if (used <= 1) {
						break;
					}
				}
			}
		}
		max = MAX(max, i - j + 1);
	}
	return max;
}
```