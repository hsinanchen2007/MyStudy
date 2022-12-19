### 解题思路
此处撰写解题思路

### 代码

```c
void visitNextRoom(int **rooms, int roomsSize, int *roomsColSize, int curRoom, bool *flag) {
    int i, nextRoom;

    for (i = 0; i < roomsColSize[curRoom]; i++) {
        nextRoom = rooms[curRoom][i];
        if (flag[nextRoom] == false) {
            flag[nextRoom] = true;
            visitNextRoom(rooms, roomsSize, roomsColSize, nextRoom, flag);
        }
    }

    return;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    bool flag[roomsSize];
    int i, cnt;

    memset(flag, 0, sizeof(bool) * roomsSize);

    flag[0] = true;
    visitNextRoom(rooms, roomsSize, roomsColSize, 0, flag);

    cnt = 0;
    for (i = 0; i < roomsSize; i++) {
        if (flag[i] == true) {
            cnt++;
        }
    }

    //printf("cnt=%d, roomsSize=%d, flag[0]=%d", cnt, roomsSize, flag[0]);
    if (cnt == roomsSize) {
        return true;
    }
    

    return false;
}
```