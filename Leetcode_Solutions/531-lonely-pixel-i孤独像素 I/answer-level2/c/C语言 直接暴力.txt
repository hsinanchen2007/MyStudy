### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/84f68f5c984da5fd39852b5b85c5032d7e3090ea1a53f0851c12eb193260541a-image.png)


### 代码

```c
int GetRowBlackCnt(char** picture, int pictureSize, int pictureColSize, int row) {
    int Cnt = 0;
    for (int i = 0; i < pictureColSize; ++i) {
        if (picture[row][i] == 'B') {
            Cnt++;
        }
    }
    return Cnt;
}

int GetColumnBlackCnt(char** picture, int pictureSize, int pictureColSize, int columinIndex) {
    int Cnt = 0;
    for (int i = 0; i < pictureSize; ++i) {
        if (picture[i][columinIndex] == 'B') {
            Cnt++;
        }
    }
    return Cnt;
}

int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize){
    int rowStaticic[510] = {0};
    int columnStaticic[510] = {0};

    for (int i = 0; i < pictureSize; ++i) {
        rowStaticic[i] = GetRowBlackCnt(picture, pictureSize, pictureColSize[0], i);
    }

    for (int j = 0; j < pictureColSize[0]; ++j) {
        columnStaticic[j] = GetColumnBlackCnt(picture, pictureSize, pictureColSize[0], j);
    }

    int cnt = 0;
    for (int k = 0; k < pictureSize; ++k) {
        if (rowStaticic[k] != 1) {
            continue;
        }
        for (int i = 0; i < pictureColSize[0]; ++i) {
            if ((columnStaticic[i] == 1) && (picture[k][i] == 'B')) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

```