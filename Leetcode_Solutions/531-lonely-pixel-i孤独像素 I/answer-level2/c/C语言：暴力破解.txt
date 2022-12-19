冲着“深度优先”来的。用深度优先的方法想了很久，根本没有暴力破解方便。坑爹。。。

```
int findLonelyPixel(char** picture, int pictureSize, int* pictureColSize){
    int col[501];
    int rows[501];
    int ret = 0;

    memset(col, 0, sizeof(col));
    memset(rows, 0, sizeof(rows));

    for(int x = 0; x < pictureSize; x++){
        for(int y = 0; y < pictureColSize[x]; y++){
            if (picture[x][y] == 'B'){
                int x1 = x + 1;
                for(; x1 < pictureSize; x1++){
                    if (picture[x1][y] == 'B'){
                        break;
                    }
                }
                int y1 = y + 1;

                for(; y1 < pictureColSize[x]; y1++){
                    if (picture[x][y1] == 'B'){
                        break;
                    }
                }
                if (x1 == pictureSize && y1 == pictureColSize[x] && col[y] == 0 && rows[x] == 0){
                    ret++;
                }
                col[y]++;
                rows[x]++;
            }
        }
    }
    return ret;
}
```
