```
#define MAXNUM 1001 
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
	int que[MAXNUM] = { 0 };
	int flag[MAXNUM] = { 0 };
	int front = 0;
	int back = 0;
	int i, j;

	flag[0] = 1;

	for (i = 0; i < roomsColSize[0]; i++){
		if (!flag[rooms[0][i]]) {
			que[back++] = rooms[0][i];
			flag[rooms[0][i]] = 1;
		}
	}

	while (front != back) {
		j = que[front++];
		for (i = 0; i < roomsColSize[j]; i++) {
			if (!flag[rooms[j][i]]) {
				que[back++] = rooms[j][i];
				flag[rooms[j][i]] = 1;
			}
		}
	}

	for (i = 0; i < roomsSize; i++) {
		if (!flag[i]) {
			return false;
		}
	}
	return true;
}
```
