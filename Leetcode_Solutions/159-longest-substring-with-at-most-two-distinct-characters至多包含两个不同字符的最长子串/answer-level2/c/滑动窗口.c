### 解题思路
此处撰写解题思路

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODE   256
#define MAX(a, b)  ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstringTwoDistinct(char *s)
{
	int left = 0;
	int right = 0;
	int count = 0;
	char *hash;
	int max = INT_MIN;

	if(!s || !strlen(s))
		return 0;

	count = 0;
	hash = (char *)malloc(MAX_NODE);
	memset(hash, 0, MAX_NODE);

	for (right = 0; right < strlen(s); right++) {
		hash[s[right]]++;
		if (hash[s[right]] == 1) {
			count++;
		}
		while(left < right && count > 2) {  /* 这个双判断 是一个关键点 */
			hash[s[left]]--;
			if (hash[s[left]] == 0) {
				count--;
			}
			left++;
		}
		max = MAX(max, right - left + 1);
	}
	return max;
}
```