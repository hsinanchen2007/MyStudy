
void FillCharAndMovePos(char* chars, int *pos, int strCnt)
{
        int nextCharPos = *pos;
        if (strCnt < 10)  {
                chars[nextCharPos] = strCnt + '0';
                nextCharPos++;
        } else if (strCnt >= 10 && strCnt < 100) {
                int shiwei = strCnt / 10;
                int gewei = strCnt % 10;
                chars[nextCharPos++] = shiwei + '0';
                chars[nextCharPos++] = gewei + '0';
        } else {
                int baiwei = strCnt / 100;
                int shiwei = (strCnt % 100) / 10;
                int gewei = (strCnt % 100) % 10;
                chars[nextCharPos++] = baiwei + '0';
                chars[nextCharPos++] = shiwei + '0';
                chars[nextCharPos++] = gewei + '0';
        }

        *pos = nextCharPos;

}
int compress(char* chars, int charsSize){
    if (chars == NULL || charsSize == 0) {
        return 0;
    }

    if (charsSize == 1) {
        return 1;
    }

    char pre = chars[0];
    int strCnt = 1;
    int i ;
    int nextCharPos = 1; //   下一个字符存放的位置

    for (i  = 1; i < charsSize; i++) {
        if (chars[i] == pre) {
            strCnt++;
        } else {
            if (strCnt == 1) {
                chars[nextCharPos] = chars[i];
                nextCharPos++;
            } else {
                FillCharAndMovePos(chars, &nextCharPos, strCnt);
                chars[nextCharPos] = chars[i];
                nextCharPos++;

            }

            pre = chars[i];
            strCnt = 1; // 下个字符的个数置1
        }
    }

            if (strCnt == 1) {
                // do nothing
            } else {
                FillCharAndMovePos(chars, &nextCharPos, strCnt);
            }

    return nextCharPos;

}