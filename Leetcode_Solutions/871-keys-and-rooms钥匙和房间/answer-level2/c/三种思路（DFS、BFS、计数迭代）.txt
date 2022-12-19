### 解题思路
都需要用一个keys数组来记录钥匙是否被拿过（同理记录门是否被开过）
1.BFS法，采用队列方式，如果门没被开过那么开门 拿钥匙
2.迭代计数，开一个门，门的数量减少一个，如果前一次的门数量和这一次门的数量相同则表示没多的钥匙了
3.DFS法，递归，有钥匙就开门，开到所拿到的钥匙门都被开过

### 代码
BFS
```c
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int *queue,rear=0,front=-1,num,*keys;
    keys = (int*)malloc(sizeof(int)*roomsSize);
    queue = (int*)malloc(sizeof(int)*roomsSize);
    memset(keys,0,sizeof(int)*roomsSize);
    keys[0] = 1;
    queue[0] = 0;
    while(rear!=front){
        num = 0;
        for (int i=front+1;i<=rear;i++){
            for (int j=0;j<roomsColSize[queue[i]];j++){
                if (keys[rooms[queue[i]][j]]==0){
                    keys[rooms[queue[i]][j]] = 1;
                    queue[rear+(++num)] = rooms[queue[i]][j];
                }
            }
        }
        front = rear;
        rear += num;
    }
    for (int i=0;i<roomsSize;i++)
        if (!keys[i])
            return false;
    return true;
}

迭代计数
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int *keys,*room,key_num,room_num,pre_num=0;
    keys = (int*)malloc(sizeof(int)*roomsSize);
    room = (int*)malloc(sizeof(int)*roomsSize);
    memset(keys,0,sizeof(int)*roomsSize);
    memset(room,0,sizeof(int)*roomsSize);
    keys[0] = 1;
    key_num = 1;
    room_num = roomsSize;
    while(room_num!=pre_num){
        pre_num = room_num;
        for (int i=0;i<roomsSize;i++){
            if (keys[i]==1 && room[i]==0){
                for (int j=0;j<roomsColSize[i];j++)
                    keys[rooms[i][j]] = 1;
                room[i] = 1;
                room_num--;
            }
        }
    }
    if (!room_num)
        return true;
    return false;
}

DFS
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int *keys;
    keys = (int*)malloc(sizeof(int)*roomsSize);
    memset(keys,0,sizeof(int)*roomsSize);
    void DFS(int x){
        if (x<0 || x>=roomsSize ||keys[x])
            return;
        keys[x] = 1;
        for (int i=0;i<roomsColSize[x];i++)
            DFS(rooms[x][i]);
    } 
    DFS(0);
    for (int i=0;i<roomsSize;i++)
        if (!keys[i])
            return false;
    return true;
}