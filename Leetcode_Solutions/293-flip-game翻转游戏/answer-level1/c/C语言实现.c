char ** generatePossibleNextMoves(char * s, int* returnSize){
    int sLen = strlen(s);
    int i;
    char **rst = (char**)malloc(sizeof(char*) * sLen);
    memset(rst, 0, sizeof(char*) * sLen);
    int count = 0;

    for (i = 0; i < sLen - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == '+') {
            rst[count] = (char*)malloc(sizeof(char) * (sLen + 1));
            memset(rst[count], 0, sizeof(char) * (sLen + 1));
            strcpy(rst[count], s);
            rst[count][i] = '-';
            rst[count][i + 1] = '-';
            count++;
        }
    }
    *returnSize = count;
    return rst;

}