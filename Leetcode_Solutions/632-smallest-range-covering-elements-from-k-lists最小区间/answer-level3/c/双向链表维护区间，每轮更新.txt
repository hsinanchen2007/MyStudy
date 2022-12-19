typedef struct BetNode {
	int start;
	int end;
	int update;
	struct BetNode* next;
	struct BetNode* last;
}BetNode;

BetNode* g_start = NULL;
BetNode* g_end = NULL;
int g_output[2];

BetNode* AddNextNode(BetNode* curNode, int start, int end, int update)
{
	BetNode* addNode = (BetNode*)malloc(sizeof(BetNode));

	addNode->start = start;
	addNode->end = end;
	addNode->update = update;
	addNode->last = curNode;
	addNode->next = curNode->next;
	curNode->next->last = addNode;
	curNode->next = addNode;

	return addNode;
}

BetNode* UpdateNode(BetNode* curNode, int start, int end)
{
	curNode->start = start;
	curNode->end = end;
	curNode->update = 1;

	return curNode;
}

BetNode* AddLastNode(BetNode* curNode, int start, int end, int update)
{
	BetNode* addNode = (BetNode*)malloc(sizeof(BetNode));

	addNode->start = start;
	addNode->end = end;
	addNode->update = update;
	addNode->last = curNode->last;
	addNode->next = curNode;
	curNode->last->next = addNode;
	curNode->last = addNode;

	return curNode;
}

void DeleteNode(BetNode* curNode)
{
	curNode->last->next = curNode->next;
	curNode->next->last = curNode->last;

	free(curNode);
}

/* 寻找左扩展 */
int SearchLeftSpread(BetNode* curNode, int idx, int num, int* value)
{
	/* 链表找完则停止 */
	if (curNode == g_end)
	{
		return 1;
	}

	/* 跳过起点小于当前值的区间，若区间包含当前值，将更新标志置1 */
	while ((curNode->start < value[idx]) && (curNode != g_end)) {
		if (curNode->end >= value[idx]) {
			curNode->update = 1;
		}
		curNode = curNode->next;
	}

	/* 找到尾部则停止 */
	if (curNode == g_end) {
		return 1;
	}

	/* 找到起点与当前值相等的区间，不再向后找;继续找下一个值 */
	if (curNode->start == value[idx]) {
		curNode->update = 1;
		curNode = curNode->next;
		return 0;
	}
	else {
		/* 若下一个值也不大于当前区间的终点，丢弃当前值 */
		if ((idx < (num - 1)) && (value[idx + 1] <= curNode->end)) {
			return 0;
		}

		/* 以当前值为起点，对区间做左扩展 */
		curNode = AddLastNode(curNode, value[idx], curNode->end, 1);
		curNode = curNode->next;
	}

	return 0;
}

/* 寻找右扩展 */
int SearchRightSpread(BetNode* curNode, int idx, int* value)
{
	/* 链表找完则停止 */
	if (curNode == g_start)
	{
		return 1;
	}

	/* 跳过终点大于当前值的区间，若区间包含当前值，将更新标志置1 */
	while ((curNode->end > value[idx]) && (curNode != g_start)) {
		if (curNode->start <= value[idx]) {
			curNode->update = 1;
		}
		curNode = curNode->last;
	}

	/* 找到尾部则停止 */
	if (curNode == g_start) {
		return 1;
	}

	/* 找到终点与当前值相等的区间，不再向后找;继续找下一个值 */
	if (curNode->end == value[idx]) {
		curNode->update = 1;
		curNode = curNode->last;
		return 0;
	}
	else {
		/* 若下一个值也不小于当前区间的起点，或当前区间已更新，丢弃当前值 */
		if (((idx > 0) && (value[idx - 1] >= curNode->start)) || (curNode->update == 1)) {
			return 0;
		}

		/* 以当前值为终点，对区间做右扩展 */
		curNode = UpdateNode(curNode, curNode->start, value[idx]);
		curNode = curNode->last;
	}

	return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize){
    int i, j, dis;
	int min_start, min_end;
	int min_dis = 300000;
	BetNode* curNode;
	BetNode* nextNode;

	g_start = (BetNode*)malloc(sizeof(BetNode));
	g_end = (BetNode*)malloc(sizeof(BetNode));
	g_start->last = NULL;
	g_start->next = g_end;
	g_end->last = g_start;
	g_end->next = NULL;
	curNode = g_start;

	for (i = 0; i < numsColSize[0]; i++) {
		if ((i > 0) && (nums[0][i] == nums[0][i - 1])) {
			continue;
		}
		else {
			curNode = AddNextNode(curNode, nums[0][i], nums[0][i], 0);
		}
	}

	for (i = 1; i < numsSize; i++) {
		/* 左扩展 */
		curNode = g_start->next;
		for (j = 0; j < numsColSize[i]; j++) {
			if (1 == SearchLeftSpread(curNode, j, numsColSize[i], nums[i])) {
				break;
			}
		}

		/* 右扩展 */
		curNode = g_end->last;
		for (j = numsColSize[i] - 1; j >= 0; j--) {
			if (1 == SearchRightSpread(curNode, j, nums[i])) {
				break;
			}
		}

		/* 清理未更新节点 */
		curNode = g_start->next;
		while (curNode != g_end) {
			if (curNode->update != 1) {
				nextNode = curNode->next;
				DeleteNode(curNode);
				curNode = nextNode;
			}
			else {
				curNode->update = 0;
				curNode = curNode->next;				
			}
		}
	}

	/* 寻找最短区间 */
	curNode = g_start->next;
	while (curNode != g_end) {
		dis = curNode->end - curNode->start;
		if (dis < min_dis) {
			min_dis = dis;
			min_start = curNode->start;
			min_end = curNode->end;
		}
		curNode = curNode->next;
	}

	free(g_start);
	free(g_end);

	g_output[0] = min_start;
	g_output[1] = min_end;
	*returnSize = 2;

	return g_output;
}