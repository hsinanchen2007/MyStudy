**思路**
根据当前位置和之前的位置计算目前的方向。
因为设置的先上下后左右，所以对当前target为z的情况做特殊处理。
```
// 每次行动最大步数为8.

char g_out[901] = {0};
char upOdown[2] = {'U', 'D'};
char leftOright[2] = {'L', 'R'};
int CalcTmpOut(char *chr, char target, char preChar)
{
    int preRow, aftRow;
    int preCol, aftCol;
    preRow = (preChar - 'a') / 5;
    preCol = (preChar - 'a') % 5;
    aftRow = (target - 'a') / 5;
    aftCol = (target - 'a') % 5;
    int upDown = (preRow < aftRow) ? 1 : 0;
    int leftRight = (preCol < aftCol) ? 1 : 0;
    int row = abs(aftRow - preRow); // 查找是U或D
    int col = abs(aftCol - preCol); // 查找是L或R
    if (target == 'z') {
        row--; // 对z做特殊处理，少往下一步，然后左右保证列的位置相同，最后再往下到z
    }
    for (int i = 0; i < row; i++) {
        chr[i] = upOdown[upDown];  // 上下走
    } 
    for (int j = row; j < col + row; j++) {
        chr[j] = leftOright[leftRight]; // 左右走
    }
    if (target == 'z') {
        chr[row + col] = 'D';
        row++;
    }
    return row + col;
}

char * alphabetBoardPath(char * target){
    int targetLen = strlen(target);
    int outLen = 0;
    memset(g_out, 0, sizeof(g_out));
    char preChar = 'a';
    for (int i = 0; i < targetLen; i++) {
        if (i > 0 && target[i] == target[i - 1]) {
            g_out[outLen] = '!';
            outLen++;
            continue;
        }
        char charCnt[9] = {'\0'};
        
        int len = CalcTmpOut(charCnt, target[i], preChar);
        memcpy(g_out + outLen, charCnt, len * sizeof(char));
        preChar = target[i];
        outLen += len;
        g_out[outLen] = '!';
        outLen++;
    }
    g_out[outLen] = '\0';
    char *output = (char *)malloc((outLen + 1) * sizeof(char));
    memcpy(output, g_out, (outLen + 1) * sizeof(char));
    return output;
}


```
