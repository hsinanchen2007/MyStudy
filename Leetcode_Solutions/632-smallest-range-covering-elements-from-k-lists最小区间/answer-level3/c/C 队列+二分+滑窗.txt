### 解题思路
题目要求是求最小区间，很容易想到使用滑窗，也是尺取法，找到最小区间；
滑窗的时候带来两个问题：
1. 怎么样快速判断窗口内命中了多少个数组的数字？
2. 如果从整个矩阵的最小值一一遍历到最大值，那么会有很多无效点，即矩阵中根本不存在的点，没有必要遍历；

第一个问题可以通过二分查找来快速找到；
第二个问题可以通过hash来去重，然后组成队列，在队列中进行滑窗；

问题解决：
1. 通过矩阵创建队列，队列由小到大排序，且不存在重复数字；
2. 在队列里的值进行滑窗；
3. 每次选中一个值之后，通过二分进行查找，确认是否命中；
4. 尺取法更新答案；


### 代码

```c
#define MAX_LEN (100000 * 2 + 10)
static int g_curNum;
static int *g_hash;
static bool *g_numHash;
static int g_queue[MAX_LEN];
static int g_front, g_rear;

static void SetHash(int n)
{
	g_numHash[n + 100000] = true;
}

static void SetQueue()
{
	int i, n;

	for (i = 0; i < MAX_LEN; i++) {
		if (g_numHash[i] == true) {
			n = i - 100000;
			g_queue[g_rear++] = n;
		}
	}
}

static int Comp(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

static void UpdateCnt(int** nums, int numsSize, int* numsColSize, int target, int ops)
{
	int i;
	bool ret;

	for (i = 0; i < numsSize; i++) {
		ret = bsearch(&target, nums[i], numsColSize[i], sizeof(int), Comp);
		if (ops == 0) {
			if (ret) {
				if (g_hash[i] == 0) {
					g_curNum++;
				}
				g_hash[i]++;
			}
		} else {
			if (ret) {
				if (g_hash[i] == 1) {
					g_curNum--;
				}
				g_hash[i]--;
			}
		}
	}
}

int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize)
{
	int i, j, begin, end;
	int minSize;
	int *ans;

	if (numsSize <= 0 || numsColSize == NULL) {
		*returnSize = 0;
		return NULL;
	}

	g_curNum = 0;
	g_hash = (int *)calloc(1, sizeof(int) * numsSize);
	ans = (int *)calloc(1, sizeof(int) * 2);
	g_numHash = (int *)calloc(1, sizeof(bool) * MAX_LEN);
	g_front = 0;
	g_rear = 0;

	for (i = 0; i < numsSize; i++) {
		for (j = 0; j < numsColSize[i]; j++) {
			SetHash(nums[i][j]);
		}
	}
	SetQueue();

	begin = g_front;
	end = g_front;
	minSize = INT_MAX;
	while (g_rear != end) {
		UpdateCnt(nums, numsSize, numsColSize, g_queue[end], 0);

		while (g_curNum == numsSize && begin <= end) {
			if (minSize > g_queue[end] - g_queue[begin]) {
				minSize = g_queue[end] - g_queue[begin];
				ans[0] = g_queue[begin];
				ans[1] = g_queue[end];
			}
			UpdateCnt(nums, numsSize, numsColSize, g_queue[begin], 1);
			begin++;
		}
		end++;
	}

	free(g_hash);
	free(g_numHash);
	*returnSize = 2;
	return ans;
}
```