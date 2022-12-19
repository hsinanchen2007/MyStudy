### 解题思路
1. 按照指令是否可以到达x, y点
2. 先到达目的地后到达故障点无问题
### 代码

```c
// 按照指令是否可以到达x, y点
bool isReach(char * command, int x, int y)
{
    bool ans = false;
    int j = 0;
    int yIndex = 0;
    int xIndex = 0;
    int cmdlen = strlen(command);
    while(1) {
        //printf("%c:%d,%d\n", command[j], xIndex, yIndex);
        if (command[j] == 'U') {
            yIndex++;
        } else if (command[j] == 'R') {
            xIndex++;
        }
        //printf("%c:%d,%d tag:%d,%d\n", command[j], xIndex, yIndex, x, y);
        if (xIndex > x || yIndex > y) {
            ans = false;
            break;
        }
        if (xIndex == x && yIndex == y) {
            ans = true;
            break;
        }
        j++;
        j = (j == cmdlen) ? 0 : j; // 循环指令
    }
    return ans;
}

bool robot(char * command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y){
    int maxLen = 0;
    int i, j;
    int cmdlen = 0;
    maxLen = (x > y)? x : y;

    if(!isReach(command, x, y)) {
        return false;
    }
    //printf("-----------------------------\n");
    for(i = 0; i < obstaclesSize; i++) {
        // 到达目的之前先到达故障点才回破损，如果先到达目的地再到达故障点不存在问题
        if (obstacles[i][0] <= x && obstacles[i][1] <= y) {
            if(isReach(command, obstacles[i][0], obstacles[i][1])) {
                return false;
            }
        }
    }   
    return true;
}
```