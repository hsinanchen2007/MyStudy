### 解题思路
典型的BSF,当所有房间都打开了就可以提前结束

### 代码

```c
#define MAX_LEN 1000

int g_list[MAX_LEN] = {0};
bool g_visit[MAX_LEN] = {false};

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int i;
    int col = 0;
    int head = 0;
    int tear = 0;
    int curRoom = 0;
    int count = roomsSize;

    memset(g_visit, 0, roomsSize * sizeof(bool));

    g_visit[0] = true;
    g_list[tear] = 0;
    tear++;
    count--;

    while (tear > head) {
        curRoom = g_list[head];
        head++;
        col = roomsColSize[curRoom];
        for (i = 0; i < col; i++) {
            if (g_visit[rooms[curRoom][i]]) {
                continue;
            }
            g_visit[rooms[curRoom][i]] = true;
            g_list[tear] = rooms[curRoom][i];
            tear++;
            count--;
            if (count == 0) {
                break;        
            }
        }
        if (count == 0) {
            break;        
        }
    }

    return count == 0;
}
```