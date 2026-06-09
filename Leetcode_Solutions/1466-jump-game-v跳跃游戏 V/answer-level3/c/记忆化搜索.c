### 解题思路
跳跃游戏，可以使用递归，判断出每个点可以跳跃的最大长度，最后找所有点中的最大值；
每个点都可以向左右两边来跳跃，每个点可以跳跃的最大值等于左、右两边的最大值 + 1，+1的原因是本身自己的点；
为提升效率，一般情况都可以进行剪枝，本题的剪枝就是：如果小步伐跳不过去，那么大步伐更跳不过去；
同样的，每个点的最大跳跃长度可以通过mem来记忆，避免重复算；
依据题意再写一个是否可以跳跃的辅助函数即可；

类似的题目很多，总结出模板后，其他题目直接套用模板即可；

### 代码

```c

#define MAX_LEN 1024
#define MAX(a, b) ((a) > (b) ? (a) : (b))
static int g_mem[MAX_LEN];

static bool CanJump(int* arr, int arrSize, int i, int j)
{
	int k, start, end;
	if (j < 0 || j >= arrSize) {
		return false;
	}

	if (arr[i] <= arr[j]) {
		return false;
	}

	if (i > j) {
		start = j + 1;
		end = i;
	} else {
		start = i + 1;
		end = j;
	}

	for (k = start; k < end; k++) {
		if (arr[k] >= arr[i]) {
			return false;
		}
	}
	return true;
}

static int Dfs(int step, int start, int* arr, int arrSize, int d)
{
	int k, direct, subAns, nextPos, leftMax, rightMax;
	leftMax = 0;
	rightMax = 0;

	if (start < 0 || start >= arrSize) {
		return -1;
	}

	if (g_mem[start] != -1) {
		return g_mem[start];
	}

	for (direct = 0; direct < 2; direct++) {
		for (k = 1; k <= d; k++) {
			if (direct == 0) {
				nextPos = start - k;
			} else {
				nextPos = start + k;
			}
			if (!CanJump(arr, arrSize, start, nextPos)) {
				/* 如果小步伐跳不过去，那么大步伐更跳不过去，直接break */
				break;
			}

			subAns = Dfs(step + 1, nextPos, arr, arrSize, d);
			if (subAns != -1) {
				if (direct == 0) {
					leftMax = MAX(leftMax, subAns);
				} else {
					rightMax = MAX(rightMax, subAns);
				}
			}	
		}	
	}

	return g_mem[start] = MAX(leftMax, rightMax) + 1;
}

int maxJumps(int* arr, int arrSize, int d)
{
	int i, ret, ans;
	ans = 1;

	for (i = 0; i < arrSize; i++) {
		g_mem[i] = -1;
	}

	for (i = 0; i < arrSize; i++) {
		ret = Dfs(1, i, arr, arrSize, d);
		if (ret > ans) {
			ans = ret;
		}
	}

	return ans;
}
```