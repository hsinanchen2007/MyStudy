#define MAXLEN 2000

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
	int queue[MAXLEN];
	int inCount[MAXLEN] = {0};
	int *order = NULL;
	int head,rear,pre,i;

	head = rear = *returnSize = 0;

	order = (int*)malloc(sizeof(int)*numCourses);

	for (i = 0; i < prerequisitesSize; i++) {
		inCount[prerequisites[i][0]]++;
	}

    //没有前驱的入队
	for (i = 0; i < numCourses; i++) {
		if (inCount[i] == 0) {
			queue[rear++] = i;
		}
	}

	while(head != rear) {
		pre = queue[head++];  //出队
		order[(*returnSize)++] = pre;
		for (i = 0; i < prerequisitesSize; i++) {
			if (pre == prerequisites[i][1]) {
				//前驱在队中，入度-1，若为0，表示没有前驱，则入队
				if (--inCount[prerequisites[i][0]] == 0) {
					queue[rear++] = prerequisites[i][0];
				}
			}
		}
	}

	if (*returnSize != numCourses) {
		*returnSize = 0;
		return NULL;
	}

	return order;
}