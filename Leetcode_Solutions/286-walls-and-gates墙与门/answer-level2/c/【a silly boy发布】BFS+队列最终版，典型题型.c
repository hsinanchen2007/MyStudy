![891BB0DE-922C-46AA-B9D0-1A1F7CEF8BAA.jpeg](https://pic.leetcode-cn.com/42e734c8c57f77d3fe75696f1954ab798ea6c2c922cbd3feaaf3ba9b333aceea-891BB0DE-922C-46AA-B9D0-1A1F7CEF8BAA.jpeg)

```
#define INF 2147483647

typedef struct ListNode286 {
	int x;
	int y;
	int level;
	struct ListNode286 *next;
} ListNode286;

ListNode286 *g_ListNode = NULL;
int g_ListNodeNum = 0;

void PushListNode(int x, int y, int level)
{
	ListNode286 *tmpGListNode = g_ListNode;
	if (g_ListNode == NULL) {
		g_ListNode = (ListNode286 *)malloc(sizeof(ListNode286));
		g_ListNode->x = x;
		g_ListNode->y = y;
		g_ListNode->level = level;
		g_ListNode->next = NULL;
	} else {
		while(tmpGListNode->next != NULL) {
			tmpGListNode = tmpGListNode->next;
		}
		tmpGListNode->next = (ListNode286 *)malloc(sizeof(ListNode286));
		tmpGListNode = tmpGListNode->next;
		tmpGListNode->x = x;
		tmpGListNode->y = y;
		tmpGListNode->level = level;
		tmpGListNode->next = NULL;
	}
	g_ListNodeNum++;
}

bool PopListNode(ListNode286 *listNode)
{
	if (g_ListNodeNum == 0) {
		return false;
	} else {
		ListNode286 *tmpGListNode = g_ListNode;
		g_ListNode = tmpGListNode->next;
		listNode->x = tmpGListNode->x;
		listNode->y = tmpGListNode->y;
		listNode->level = tmpGListNode->level;
		listNode->next = tmpGListNode->next;
		g_ListNodeNum--;
		return true;
	}
}

void SubFuncBFS(int** rooms, int roomsSize, int* roomsColSize, int **visited)
{
	ListNode286 tmpListNode;
	bool popValidFlag = false;

	popValidFlag = PopListNode(&tmpListNode);
	if (popValidFlag == true) {
		visited[tmpListNode.x][tmpListNode.y] = 1;
		if (rooms[tmpListNode.x][tmpListNode.y] > tmpListNode.level) {
			rooms[tmpListNode.x][tmpListNode.y] = tmpListNode.level;
		}

		if ((tmpListNode.x >= 0) && (tmpListNode.x <= roomsSize - 1)
			&& (tmpListNode.y - 1 >= 0) && (tmpListNode.y - 1 <= *roomsColSize - 1)
			&& (rooms[tmpListNode.x][tmpListNode.y - 1] != -1)
			&& (rooms[tmpListNode.x][tmpListNode.y - 1] != 0)) {
				if (visited[tmpListNode.x][tmpListNode.y - 1] == 0) {
					PushListNode(tmpListNode.x, tmpListNode.y - 1, tmpListNode.level + 1);
				}
			}
		if ((tmpListNode.x + 1 >= 0) && (tmpListNode.x + 1 <= roomsSize - 1)
			&& (tmpListNode.y >= 0) && (tmpListNode.y <= *roomsColSize - 1)
			&& (rooms[tmpListNode.x + 1][tmpListNode.y] != -1)
			&& (rooms[tmpListNode.x + 1][tmpListNode.y] != 0)) {
				if (visited[tmpListNode.x + 1][tmpListNode.y] == 0) {
					PushListNode(tmpListNode.x + 1, tmpListNode.y, tmpListNode.level + 1);
				}
			}	
		if ((tmpListNode.x >= 0) && (tmpListNode.x <= roomsSize - 1)
			&& (tmpListNode.y + 1 >= 0) && (tmpListNode.y + 1 <= *roomsColSize - 1)
			&& (rooms[tmpListNode.x][tmpListNode.y + 1] != -1)
			&& (rooms[tmpListNode.x][tmpListNode.y + 1] != 0)) {
				if (visited[tmpListNode.x][tmpListNode.y + 1] == 0) {
					PushListNode(tmpListNode.x, tmpListNode.y + 1, tmpListNode.level + 1);
				}
			}	
		if ((tmpListNode.x - 1 >= 0) && (tmpListNode.x - 1 <= roomsSize - 1)
			&& (tmpListNode.y >= 0) && (tmpListNode.y <= *roomsColSize - 1)
			&& (rooms[tmpListNode.x - 1][tmpListNode.y] != -1)
			&& (rooms[tmpListNode.x - 1][tmpListNode.y] != 0)) {
				if (visited[tmpListNode.x - 1][tmpListNode.y] == 0) {
					PushListNode(tmpListNode.x - 1, tmpListNode.y, tmpListNode.level + 1);
				}
			}
		SubFuncBFS(rooms, roomsSize, roomsColSize, visited);
	} else {
		return;
	}
}

void wallsAndGates(int** rooms, int roomsSize, int* roomsColSize){
	if ((rooms == NULL) || (roomsSize == 0) || (roomsColSize == NULL) || (*roomsColSize == 0)) {
		return;
	}

	int i;
	int j;
	int k;
	int level = 0;
	int **visited = (int **)malloc(roomsSize * sizeof(int *));
	for (i = 0; i < roomsSize; i++) {
		visited[i] = (int *)malloc(*roomsColSize * sizeof(int));
		memset(visited[i], 0, *roomsColSize * sizeof(int));
	}
	for (i = 0; i < roomsSize; i++) {
		for (j = 0; j < *roomsColSize; j++) {
			if (rooms[i][j] == 0) {
				PushListNode(i, j, level);
				SubFuncBFS(rooms, roomsSize, roomsColSize, visited);
				for (k = 0; k < roomsSize; k++) {
					memset(visited[k], 0, *roomsColSize * sizeof(int));
				}
			}
		}
	}
}


```
