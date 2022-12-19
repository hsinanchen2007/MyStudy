### 解题思路
1. 直接贪心，比较难想到。总体思路，有新的会议就直接新开一个会议室，在每次开新的会议室之前判断是否有结束的会议，动态的维护会议室个数
1. 贪心区间调度问题
2. 差分法
### 代码

【贪心】16 ms
```
#define MAX(a, b) ((a) > (b) ? (a) : (b))
static int Comp(const void *a,const void *b)
{
	int *pa = (int *)a;
	int *pb = (int *)b;
	return *pa - *pb;
}

static int GenAns(int *start, int *end, int len)
{
	/* 总体思路，有新的会议就直接新开一个会议室，在每次开新的会议室之前判断是否有结束的会议
	   动态的维护会议室个数
	*/
	int ansRoom = 0, tmpRoom = 0;
	int startIndex, endIndex = 0;

	for (startIndex = 0; startIndex < len; startIndex++) {
		tmpRoom++;
		while (end[endIndex] <= start[startIndex]) {
			tmpRoom--;
			endIndex++;
		}
		ansRoom = MAX(ansRoom, tmpRoom);
	}
	return ansRoom;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize)
{
	int *start  = (int *)calloc(1, sizeof(int) * intervalsSize);
	int *end  = (int *)calloc(1, sizeof(int) * intervalsSize);
	int i;

	for (i = 0; i < intervalsSize; i++) {
		start[i] = intervals[i][0];
		end[i] = intervals[i][1];
	}

	qsort(start, intervalsSize, sizeof(int), Comp);
	qsort(end, intervalsSize, sizeof(int), Comp);
	return GenAns(start, end, intervalsSize);
}
```

【贪心 - 区间调度】188 ms
```
#define MAX(a, b) ((a) > (b) ? (a) : (b))
static int Comp(void *a, void *b)
{
	int *pa = *(int **)a;
	int *pb = *(int **)b;
	if (pa[1] == pb[1]) {
		return pa[0] - pb[0];
	}
	return pa[1] - pb[1];
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
	int a1, b1, a2, b2, i, j, ans, tmp;

	if (intervalsSize <= 0) {
		return 0;
	}
	qsort(intervals, intervalsSize, sizeof(int *), Comp);
	ans = 0;
	for (i = 0; i < intervalsSize; i++) {
		a1 = intervals[i][0];
		b1 = intervals[i][1];
		tmp = 1;
		for (j = i + 1; j < intervalsSize; j++) {
			a2 = intervals[j][0];
			b2 = intervals[j][1];
			if (b1 > a2) {
				tmp++;
			}
		}
		ans = MAX(ans, tmp);
	}
	return ans;
}
```


【差分】84 ms
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_N 1000050

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize){
	int *arr = (int *)calloc(1, sizeof(int) * MAX_N);
	int *status = (int *)calloc(1, sizeof(int) * MAX_N);
	int left, right, val, i, maxval, ans;

	maxval = 0;
	ans = 0;
	for (i = 0; i < intervalsSize; i++) {
		left = intervals[i][0];
		right = intervals[i][1];
		arr[left] += 1;
		arr[right] -= 1;
		maxval = MAX(maxval, right);
 	}

	for (i = 0; i <= maxval; i++) {
		status[i + 1] = status[i] + arr[i];
		ans = MAX(ans, status[i + 1]);
	}
	free(arr);
	free(status);
	return ans;
}


```