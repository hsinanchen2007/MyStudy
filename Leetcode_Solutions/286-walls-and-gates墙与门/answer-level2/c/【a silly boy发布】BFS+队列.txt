![459DDBE3-43A3-4F7B-B302-5B092A02D3E2.jpeg](https://pic.leetcode-cn.com/c5cf8d1f408fd2bbe2ff0e27f43684a6200676007f15babdf6282b35d9d2364e-459DDBE3-43A3-4F7B-B302-5B092A02D3E2.jpeg)

```
#define INF 2147483647

struct tt127ListNode{
	int xPos;
	int yPos;
	int level;
	struct tt127ListNode *tt127nextListNode;
};

//全局链表
struct tt127ListNode *tt127FinalListNode;
int gLevel = 0;
int outputLevel = 0;

struct tt127ListNode * addtt127ListNode(int xPos, int yPos, int level) {
	struct tt127ListNode *tt127FinalListNodeCopy = tt127FinalListNode;

	if (tt127FinalListNode == NULL) {
		tt127FinalListNode = (struct tt127ListNode *)malloc(sizeof(struct tt127ListNode));
		tt127FinalListNode->level = level;
		tt127FinalListNode->xPos = xPos;
		tt127FinalListNode->yPos = yPos;
		tt127FinalListNode->tt127nextListNode = NULL;
		return tt127FinalListNode;
	} else {
		struct tt127ListNode *tt127InputListNodeCopy_2 = tt127FinalListNode;
		while(tt127FinalListNodeCopy->tt127nextListNode != NULL) {
			tt127FinalListNodeCopy = tt127FinalListNodeCopy->tt127nextListNode;
		}
		tt127FinalListNodeCopy->tt127nextListNode = (struct tt127ListNode *)malloc(sizeof(struct tt127ListNode));
		tt127FinalListNodeCopy->tt127nextListNode->xPos = xPos;
		tt127FinalListNodeCopy->tt127nextListNode->yPos = yPos;
		tt127FinalListNodeCopy->tt127nextListNode->level = level;
		tt127FinalListNodeCopy->tt127nextListNode->tt127nextListNode = NULL;
		tt127FinalListNodeCopy = tt127FinalListNodeCopy->tt127nextListNode;
		return tt127FinalListNode;
	}
}

bool popHeadtt127ListNode(struct tt127ListNode *tt127InputListNodeCopy_2) {
	struct tt127ListNode *tt127InputListNodeCopy;

	if (tt127FinalListNode == NULL) {
		return false;
	} else {
		tt127InputListNodeCopy = tt127FinalListNode;
		tt127FinalListNode = tt127FinalListNode->tt127nextListNode;
		memcpy(tt127InputListNodeCopy_2, tt127InputListNodeCopy, sizeof(struct tt127ListNode));
		free(tt127InputListNodeCopy);
		tt127InputListNodeCopy = NULL;
		return true;
	}
}

struct tt127ListNode tt127ListNodeTmp = { 0 };
bool isGlobalFlag = false;

void bfs286(int** rooms, int roomsSize, int* roomsColSize, int x, int y, int **visit, int level) {


	if ((x < 0) || (x >= roomsSize) || y < 0 || y >= *roomsColSize) {
		return;
	}

	if (visit[x][y] == 1) {
		return;
	}
	if (rooms[x][y] == -1) {
		return;
	}

	if ((rooms[x][y] == 0) && (isGlobalFlag == false)) {
		tt127FinalListNode = addtt127ListNode(x, y, level);
		isGlobalFlag = true;
	}else if (rooms[x][y] == INF) {
		tt127FinalListNode = addtt127ListNode(x, y, level);
		rooms[x][y] = level;	
	}else if(rooms[x][y] != -1) {
		if (level < rooms[x][y]) {
			tt127FinalListNode = addtt127ListNode(x, y, level);
			rooms[x][y] = level; 
		}
	}else {
		return;
	}

	int xPosTmp = 0;
	int yPosTmp = 0;
	bool tmpFlagPop = false;
	tmpFlagPop = popHeadtt127ListNode(&tt127ListNodeTmp);

	if (tmpFlagPop == false) {
		return;
	}else {
		xPosTmp = tt127ListNodeTmp.xPos;
		yPosTmp = tt127ListNodeTmp.yPos;
	}
	level++;
	bfs286(rooms, roomsSize, roomsColSize, x - 1, y, visit, level);
	bfs286(rooms, roomsSize, roomsColSize, x + 1, y, visit, level);
	bfs286(rooms, roomsSize, roomsColSize, x, y - 1, visit, level);
	bfs286(rooms, roomsSize, roomsColSize, x, y + 1, visit, level);
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
	int level = 0;
	tt127FinalListNode = NULL;
	int **visit = (int **)malloc(roomsSize * sizeof(int *));
	for (int i = 0; i < roomsSize; i++) {
		visit[i] = (int *)malloc((*roomsColSize) * sizeof(int));
		memset(visit[i], 0, (*roomsColSize) * sizeof(int));
	}

	for (int i = 0; i < roomsSize; i++) {
		for (int j = 0; j < (*roomsColSize); j++) {
			if (rooms[i][j] == 0) {
				isGlobalFlag = false;
				level = 0;
				bfs286(rooms, roomsSize, roomsColSize, i, j, visit, level);
			}
		}
	}

	if (tt127FinalListNode != NULL) {
		free(tt127FinalListNode);
	}
	isGlobalFlag = false;

}
```
