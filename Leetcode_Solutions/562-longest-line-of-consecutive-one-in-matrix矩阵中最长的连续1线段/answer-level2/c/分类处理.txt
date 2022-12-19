### 解题思路
没啥思路，遍历。
一个变量坑了我一下，这种分支较多的方法，写代码要注意。

### 代码

```c
int longestLine(int** M, int MSize, int* MColSize){
    int max = 0;
    int tmp = 0;
    int k   = 0;
    int debug = 0;
    if (MSize <= 0) {
        return 0;
    } 
    // 遍历行
    for (int i = 0; i < MSize; i++) {
        tmp = 0;
        for (int j = 0; j < *MColSize; j++) {
            if (M[i][j] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
        }
    }
    if(debug) printf("row max %d\n",max);
    // 遍历列
    for (int i = 0; i < *MColSize; i++) {
        tmp = 0;
        for (int j = 0; j < MSize; j++) {
            if (M[j][i] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
        }
    }
    if(debug) printf("col max %d\n",max);
    // 遍历对角线.
    for (int i = MSize-1; i >= 0; i--) {
        k = i;
        tmp = 0;
        for (int j = 0; j < *MColSize && k < MSize; j++) {
            if (M[k][j] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
            k++;
        }       
    }
    if(debug) printf("1 max %d\n",max);
    for (int j = 1; j < *MColSize; j++) {
        k = j;
        tmp = 0;
        for (int i = 0; i < MSize && k < *MColSize; i++) {
            if (M[i][k] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
            k++;
        }
    } 
    if(debug) printf("2 max %d\n",max);      
    // 遍历反对角线
    for (int j = 0; j < *MColSize; j++) {
       k = j;
       tmp = 0;
       for (int i = 0; i < MSize && k >= 0; i++) {
          if (M[i][k] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
            k--; 
       }
    }
    if(debug) printf("3 max %d\n",max);
    for (int i = 1; i < MSize; i++) {
       k = i;
       tmp = 0;
       for (int j = *MColSize-1; j >= 0 && k < MSize; j--) {
          if (M[k][j] != 0) {
                tmp++;
                max = max > tmp ? max : tmp; // 每次记录最大值
            }else {
                tmp = 0;
            }
            k++; 
       }
    }
    if(debug) printf("4 max %d\n",max);
    return max;
}
```