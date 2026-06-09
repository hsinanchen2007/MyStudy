int max(int a, int b)
{
    if(a>b) 
        return a;
    return b;
}

int longestPalindromeSubseq(char * s){
    int slen = strlen(s);
    int **arrRow = (int **)malloc(sizeof(int *) * slen);
    int i;
    for (i = 0; i < slen; i++) {
        arrRow[i] = (int *)malloc(sizeof(int) * slen);
        memset(arrRow[i], 0, sizeof(int) * slen);
    }

    int row;
    int col;
    for (row = slen - 1; row >= 0; row--) {
        arrRow[row][row] = 1;
        for (col = row + 1; col < slen; col++) {
            if (s[row] == s[col]) {
                arrRow[row][col] = arrRow[row + 1][col - 1] + 2;
            } else {
                arrRow[row][col] = max(arrRow[row][col - 1], arrRow[row + 1][col]);
            }
        }

    }
    
    return arrRow[0][slen - 1];

}