### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f592cf2deb8590664b8353bb8cac547f591dd390408ccaccff41d840624646d0-image.png)

### 代码

```c
void cmdCount(char * cmd, int *pxNum, int *pyNum) { //计算命令中x、y的个数
    char *p = cmd;

    *pxNum = 0;
    *pyNum = 0;

    while (*p != '\0') {
        if ('U' == *p) {
            (*pyNum)++;
        }
        if ('R' == *p) {
            (*pxNum)++;
        }
        p++;
    }
    return;
}

int getyNum(char * cmd, int xNum) { //计算一组命令中，n个x前面的y个数
    int yNum = 0;
    int x = 0;
    char *p = cmd;

    while ((x < xNum) && ('\0' != *p)) {
        if ('R' == *p) {
            x++;
        }
        if ('U' == *p) {
            yNum++;
        }
        p++;
    }
    return yNum;
}

int getyNum2(char *cmd, int xNum) {//计算一组命令中，n个x到下一个x之间y的个数
    int yNum = 0;
    int x = 0;
    char *p = cmd;

    while ((x < xNum) && ('\0' != *p)) {
        if ('R' == *p) {
            x++;
        }
        p++;
    }
    while (('R' != *p) && ('\0' != *p)) {
        yNum++;
        p++;
    }
    return yNum;
}

bool can2Dest(char * cmd, int x, int y) { //判断能否到达终点

    int xCnt; //x到达目的需要的命令组数
    int xPos; //x在一组命令中的偏移
    int yCnt; //x到达目的需要的命令组数
    int yPos;
    int xNum; //一组命令中x的个数
    int yNum;
    int yNum1;
    int yNum2;
    int tmp;

    cmdCount(cmd, &xNum, &yNum);
    xPos = x % xNum;
    yPos = y % yNum;

    xCnt = (0 == xPos) ? x/xNum : x/xNum + 1;
    yCnt = (0 == yPos) ? y/yNum : y/yNum + 1;

    if ((xCnt > yCnt + 1) || (yCnt > xCnt + 1)) {
        return false;
    }

    yNum1 = getyNum(cmd, xPos);
    yCnt = (0 == xPos) ? xCnt : (xCnt - 1);
    tmp = yCnt * yNum + yNum1;
    if (tmp > y) {
        return false;
    }
    if (tmp == y) {
        return true;
    }
    //以下是y还没达到目的值得处理
    yNum2 = getyNum2(cmd, xPos);
    if (yNum2 + tmp >= y){
        return true;
    }
    return false;
}



bool robot(char * command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y){

    int cmdLen;
    int i;
    int j;
    int x1 = 0;
    int y1 = 0;

    if(NULL == command) {
        return false;
    }

    if (false == can2Dest(command, x, y)) {
        return false;
    }

    //只判断目的范围内的障碍物
    for (i = 0; i < obstaclesSize; i++) {
        if ((obstacles[i][0] >= x) && (obstacles[i][1] >= y)) {
            continue;
        }
        if (true == can2Dest(command, obstacles[i][0], obstacles[i][1])) {
            return false;
        }
    }

    return true;
}
```