int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
    int *resultData = malloc(sizeof(int) * 2);
    int temp = 0;
    int rows = 1;
    for (int i = 0; i < strlen(S); i++) {
        if ((temp + widths[S[i] - 'a']) > 100) {
            rows++;
            temp = 0;
            temp += widths[S[i] - 'a'];
        } else {
            temp += widths[S[i] - 'a'];
        }
    }
    resultData[0] = rows;
    resultData[1] = temp;
    *returnSize = 2;
    return resultData;
}