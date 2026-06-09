![206AE3BA-02C4-40E8-B02F-87AE718ED219.jpeg](https://pic.leetcode-cn.com/b7dc4e04b596943e50658e1b796f3891c4c86677171cd51935a3119ed67515b7-206AE3BA-02C4-40E8-B02F-87AE718ED219.jpeg)

```
#define INF 2147483647

void SubFuncDFS(int** rooms, int roomsSize, int* roomsColSize, int i, int j, int level, int **roomsFlag)
{
	if ((i < 0) || (i > roomsSize - 1) || (j < 0) || (j > *roomsColSize - 1)) {
		return;
	}
	if (roomsFlag[i][j] == 1) {
		return;
	}
	roomsFlag[i][j] = 1;

	if (rooms[i][j] == -1) {
		return;
	}

	if ((rooms[i][j] > level) && (rooms[i][j] != 0)) {
		rooms[i][j] = level;
	}

	level++;

	if ((i >= 0) && (i <= roomsSize - 1) && (j -1 >= 0) && (j - 1 <= *roomsColSize - 1) && (rooms[i][j - 1] != 0)) {
		SubFuncDFS(rooms, roomsSize, roomsColSize, i, j - 1, level, roomsFlag);
	}
	if ((i + 1 >= 0) && (i + 1 <= roomsSize - 1) && (j >= 0) && (j <= *roomsColSize - 1) && (rooms[i + 1][j] != 0)) {
		SubFuncDFS(rooms, roomsSize, roomsColSize, i + 1, j, level, roomsFlag);
	}
	if ((i >= 0) && (i <= roomsSize - 1) && (j + 1 >= 0) && (j + 1 <= *roomsColSize - 1) && (rooms[i][j + 1] != 0)) {
		SubFuncDFS(rooms, roomsSize, roomsColSize, i, j + 1, level, roomsFlag);
	}
	if ((i - 1 >= 0) && (i - 1 <= roomsSize - 1) && (j >= 0) && (j <= *roomsColSize - 1) && (rooms[i - 1][j] != 0)) {
		SubFuncDFS(rooms, roomsSize, roomsColSize, i - 1, j, level, roomsFlag);
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

	int **roomsFlag = (int **)malloc(roomsSize * sizeof(int *));
	for (i = 0; i < roomsSize; i++) {
		roomsFlag[i] = (int *)malloc(*roomsColSize * sizeof(int));
		memset(roomsFlag[i], 0, *roomsColSize * sizeof(int));
	}
	for (i = 0; i < roomsSize; i++) {
		for (j = 0; j < *roomsColSize; j++) {
			if (rooms[i][j] == 0) {
				printf("i: %d, j: %d\n", i, j);
				SubFuncDFS(rooms, roomsSize, roomsColSize, i, j, level, roomsFlag);
			}
			for (k = 0; k < roomsSize; k++) {
				roomsFlag[k] = (int *)malloc(*roomsColSize * sizeof(int));
				memset(roomsFlag[k], 0, *roomsColSize * sizeof(int));
			}
		}
	}
}


```
