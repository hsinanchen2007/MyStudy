char * intToRoman(int num){

    // printf("in num---------> %d \r\n", num);
    char romanA[10][10] = {"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char romanB[10][10] = {"0", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char romanC[10][10] = {"0", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char romanD[10][10] = {"0", "M", "MM", "MMM", "MMM", "MMM", "MMM", "MMM", "MMM", "MMM"};

    char tempBuf[100] = {'\0'};
    int  QIdx = (int)(num / 1000); // qian
    int  QYu = num % 1000;
    int  BIdx = (int)(QYu / 100); // bai
    int BYu = QYu % 100; // bai
    int  SIdx = (int)(BYu / 10);
    int  GIdx = BYu % 10;
    int len = 0;
    char* pout = NULL;
    int size = 0;

    if (QIdx > 0) {
        size = strlen(romanD[QIdx]);
        memcpy(tempBuf + len, romanD[QIdx], sizeof(size));
        len += size;
    }
    if (BIdx > 0) {
        size = strlen(romanC[BIdx]);
        memcpy(tempBuf + len, romanC[BIdx], sizeof(size));
        len += size;
    }

    if (SIdx > 0) {
        size = strlen(romanB[SIdx]);
        memcpy(tempBuf + len, romanB[SIdx], sizeof(size));
        len += size;
    }
    if (GIdx > 0) {
        size = strlen(romanA[GIdx]);
        memcpy(tempBuf + len, romanA[GIdx], sizeof(size));
        len += size;
    }
    
    pout = (char*)malloc(sizeof(char) * len + 2);
    memset(pout, '\0', sizeof(char) * len + 2);
    memcpy(pout, tempBuf, sizeof(char) * len);
    pout[len] = '\0';

    return pout;
}