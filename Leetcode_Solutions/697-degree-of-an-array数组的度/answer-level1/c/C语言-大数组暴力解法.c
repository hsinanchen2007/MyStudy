### 解题思路
#1. 计算数组的度：申请长度为50000的数组，用以记录以nums[x]为下标的重复次数，最大的重复次数即为数组的度；（可能有多个相同最大值）
#2. 与数组的度相同的子串长度 = 数组中每个元素出现的最后一个位置作为结束位 - 第一个与数组的度相同的元素 （每次计算后，都把与该下标的重复次数置为零，避免重复计算）
#3. 取2中的最小值；
### 代码

```c
#define MAX_LEN 50000

int g_index[MAX_LEN];
int g_grade[MAX_LEN];

int findShortestSubArray(int* nums, int numsSize){
	int i;
	int maxGrade = 0;
	int maxGradeLen = MAX_LEN;
	if (numsSize == 0 || nums == NULL) {
		return 0;
	}
	memset(g_grade, 0, sizeof(g_grade));
	for (i = 0; i < numsSize; i++) {
		g_grade[*(nums + i)]++;
		g_index[*(nums + i)] = i;
		if (maxGrade < g_grade[*(nums + i)]) {
			maxGrade = g_grade[*(nums + i)];
		}
	}

	for (i = 0; i < numsSize; i++) {
		if (g_grade[*(nums + i)] == maxGrade) {
			if (maxGradeLen > g_index[*(nums + i)] - i + 1) {
				maxGradeLen = g_index[*(nums + i)] - i + 1;
			}
		}
		g_grade[*(nums + i)] = 0;
	}

	return maxGradeLen;
}
```