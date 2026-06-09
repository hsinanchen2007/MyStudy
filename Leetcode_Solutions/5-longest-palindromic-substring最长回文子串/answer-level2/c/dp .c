//dp[i][j] = s[i] == s[j] && ((j - i == 1) || dp[i+1][j-1])

char * longestPalindrome(char * s){
    if (s == NULL) {
        return NULL;
    }

    int slen = strlen(s);
    //isMirror[i][j] 表示从s[i] 到 s[j]的字符串是否是回文
    unsigned char **isMirror = (unsigned char **)malloc(sizeof(unsigned char *) * slen);

    int start = 0; //最长回文的起始位置
    int end = 0; //最长回文的结束位置
    int row;
    int col;

    int i;
    for (i = 0; i < slen; i++) {
        isMirror[i] = (unsigned char *)malloc(sizeof(unsigned char) * slen);
        memset(isMirror[i], 0, sizeof(unsigned char) * slen);
    }

    for (row = slen - 1; row >=0; row--) {
        isMirror[row][row] = 1;
        for (col = row + 1; col < slen; col++) {
            isMirror[row][col] = ((s[row] == s[col]) && ((col - row == 1) || isMirror[row + 1][col - 1]));
            if (isMirror[row][col]) {
                if ((col - row) >= (end - start)) {
                    end = col;
                    start = row;
                }
            }


        }

    }

    char *palindrome;
    if (end - start == 0) {
        palindrome = (char *)malloc(sizeof(char) * 2);
        palindrome[0] = s[start];
        palindrome[1] = 0;
        return palindrome;
    }

    palindrome = (char *)malloc(sizeof(char) * (end - start + 2));
    for (i = start; i <= end; i++) {
        palindrome[i - start] = s[i];
    }
    palindrome[i - start] = 0;
    return palindrome;
}