### 解题思路
此处撰写解题思路

### 代码

```c
#define min(x, y) ((x) > (y) ? (y) : (x))

#define max(x, y) ((x) > (y) ? (x) : (y))

struct MapList {
	int x;
	int y;
	int step;
	int oriStatus;
	struct MapList *next;
};

int BFS(struct MapList *head, int** grid, int gridSize, int* gridColSize)
{
	struct MapList *tail = head;
	struct MapList *tmpL = head;

	int i;
	int j;
	int cntL = 0;
	for (i = 0; i < gridSize; i++) {
		for (j = 0; j < gridColSize[i]; j++) {
			if (grid[i][j] == 1) {
				tail->next = (struct MapList *)malloc(sizeof(struct MapList));
				tail = tail->next;
				tail->x = i;
				tail->y = j;
				tail->step = 0;
				tail->oriStatus = 1;
				tail->next = NULL;
				cntL++;
			}
		}
	}
	printf("i %d j %d cntL %d \n", i, j, cntL);
	if (cntL == 0 || cntL == i * j) {
		return -1;
	}

	int tx;
	int ty;
	int maxStep = 0;
	tmpL = head->next;
	while (1) {
		if (cntL == i * j) {
			return maxStep;
		}
		tx = tmpL->x;
		ty = tmpL->y;
		printf("tx %d ty %d maxStep %d \n", tx, ty, maxStep);
		if (tx - 1 >= 0 && grid[tx - 1][ty] == 0) {
			tail->next = (struct MapList *)malloc(sizeof(struct MapList));
			tail = tail->next;
			tail->x = tx - 1;
			tail->y = ty;
			tail->step = tmpL->step + 1;
			tail->oriStatus = 0;
			tail->next = NULL;
			cntL++;
			grid[tx - 1][ty] = tail->step;
			maxStep = max(maxStep, tail->step);
			printf("tx - 1 tail->step %d\n", tail->step);
		}
		if (tx + 1 < gridSize && grid[tx + 1][ty] == 0) {
			tail->next = (struct MapList *)malloc(sizeof(struct MapList));
			tail = tail->next;
			tail->x = tx + 1;
			tail->y = ty;
			tail->step = tmpL->step + 1;
			tail->oriStatus = 0;
			tail->next = NULL;
			cntL++;
			grid[tx + 1][ty] = tail->step;
			maxStep = max(maxStep, tail->step);
			printf("tx + 1 tail->step %d\n", tail->step);
		}
		if (ty - 1 >= 0 && grid[tx][ty - 1] == 0) {
			tail->next = (struct MapList *)malloc(sizeof(struct MapList));
			tail = tail->next;
			tail->x = tx;
			tail->y = ty - 1;
			tail->step = tmpL->step + 1;
			tail->oriStatus = 0;
			tail->next = NULL;
			cntL++;
			grid[tx][ty - 1] = tail->step;
			maxStep = max(maxStep, tail->step);
			printf("ty - 1 tail->step %d\n", tail->step);
		}
		if (ty + 1 < gridColSize[0] && grid[tx][ty + 1] == 0) {
			tail->next = (struct MapList *)malloc(sizeof(struct MapList));
			tail = tail->next;
			tail->x = tx;
			tail->y = ty + 1;
			tail->step = tmpL->step + 1;
			tail->oriStatus = 0;
			tail->next = NULL;
			cntL++;
			grid[tx][ty + 1] = tail->step;
			maxStep = max(maxStep, tail->step);
			printf("ty + 1 tail->step %d\n", tail->step);
		}

		printf("maxStep %d cntL %d \n", maxStep, cntL);
		tmpL = tmpL->next;
		if (tmpL == NULL) {
			break;
		}
	}
	return maxStep;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
	struct MapList *head = (struct MapList *)malloc(sizeof(struct MapList));
	head->step = 0;
	head->next = NULL;

	int ret = BFS(head, grid, gridSize, gridColSize);

	return ret;

}
```