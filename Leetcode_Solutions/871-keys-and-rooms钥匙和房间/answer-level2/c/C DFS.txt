### 解题思路
C + DFS 无话可说
### 代码

```c

void func(int** rooms,int k, int* tmp, int* roomsColSizes)
{
    for(int j = 0;j < roomsColSizes[k]; j++) {
        int index = rooms[k][j];
        if(0 == tmp[index]) {
            tmp[index] = 1;
            func(rooms, index, tmp, roomsColSizes);
        }
    }
}
 
bool canVisitAllRooms(int** rooms, int roomsRowSize, int *roomsColSizes) 
{
    int m = roomsRowSize;
    int* tmp = (int*)malloc(sizeof(int) * m);
    memset(tmp, 0, sizeof(int)*m);
    tmp[0] = 1;
    func(rooms, 0, tmp, roomsColSizes);
    for(int i = 0; i < m; i++)
    {
        if(0 == tmp[i]) {
            return false;
        }
    }
    return true;
}
```