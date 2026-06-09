char * convert(char * s, int numRows){
    int len =  strlen(s);
    int* num = NULL;
    bool goDown = 0;
    int row = 0;
    int i;
    char* ret = NULL;
    char (*a)[len + 1] = NULL;

    if (numRows == 1) {
        return s;
    }

    a = (char(*)[len + 1])malloc((len + 1) * numRows);
    if (a == NULL) {
        return NULL;
    }
    memset(a, '\0', (len + 1) * numRows);

    num = (int *)malloc(sizeof(int) * numRows);
    if (num == NULL) {
        free(a);
        a = NULL;
        return NULL;
    }
    memset(num, 0, sizeof(int) * numRows);

    for (i = 0; i < len; i++) {
        a[row][num[row]] = s[i];
        if (row == 0 || row == numRows - 1) {
            goDown = !goDown;
        }
        num[row] = num[row] + 1;
        row += goDown ? 1 : -1;
    }

    ret = (char *)malloc(len + 1);
    if (ret == NULL) {
        free(a);
        a = NULL;
        free(num);
        num = NULL;
        return NULL;
    }
    memset(ret, '\0', len + 1);

    for (i = 0; i < numRows; i++) {
        strcat(ret, a[i]);
    }

    free(a);
    a = NULL;
    free(num);
    num = NULL;

    return ret;
}