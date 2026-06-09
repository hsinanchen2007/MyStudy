### 解题思路
纯用数组解决，等我进个阶再回来收拾你，可恶

### 代码

```c

bool isValidgroup(int *arr, int* arrSize) {
    int i,j;
    bool flag = true;
    for (i=0; i<*arrSize; i++) {
        for (j=i+1; j<*arrSize; j++) {
            if (arr[i]==arr[j]) {
                flag=false;
                break;   
            }
        }
        if (!flag) break;
        arr[i] = 0;
    }
    *arrSize = 0;
    return flag;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int i, j, k, m=0;
    int cnt1=0;
    int cnt2=0;
    *boardColSize = 9;
    //判断行、列是否有相等的数字
    for (i=0; i<boardSize; i++) {
        for (j=0; j<boardSize; j++) {
            for (k=j+1; k<boardSize; k++) {
                if ((board[i][j]==board[i][k]&&board[i][j]!='.')
                    ||(board[j][i]==board[k][i]&&board[k][i]!='.')) {
                    goto out;
                }
            }
        }
    }

    int b[18] = {0};
    //判断九宫格内是否有重复的数字
    // [0,0]->[2,2]、[3,3]->[5,5]、[6,6]->[8,8]
    while (m!=9) {
        for (i=m; i<m+3; i++) {
            for (j=m; j<m+3; j++) {
                if (board[i][j]!='.')
                b[cnt1++]=board[i][j];
            }
        }
        if(!isValidgroup(b, &cnt1)) goto out;
        m +=3;
    }
    int a[] = {0,3,0,6,3,6};
    m=0;
    // [0,3]->[2,5]、[0,6]->[2,8]、[3,6]->[5,8]
    // [3,0]->[5,2]、[6,0]->[8,2]、[6,3]->[8,5]
    while (m!=6) {
        for (i=a[m]; i<a[m]+3; i++) {
            for (j=a[m+1]; j<a[m+1]+3; j++) {
                if (board[i][j]!='.')
                b[cnt1++]=board[i][j];
                if (board[j][i]!='.')
                b[9+cnt2++]=board[j][i];
            }
        }
        if(!isValidgroup(b, &cnt1)) goto out;
        if(!isValidgroup(&b[9], &cnt2)) goto out;
        m+=2;
    }

    return 1;
    out: 
    return 0;
}
```