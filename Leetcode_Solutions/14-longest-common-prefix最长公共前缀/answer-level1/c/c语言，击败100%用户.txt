char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0;
    int j;
    char *str = strs[0];

    if (strsSize == 0) {
        return "";
    }
    
    for (i = 1; i < strsSize; i++) {
        for (j = 0; str[0] != '\0' && strs[i][j] != '\0'; j++) {
            if (strs[i][j] != str[j]) {
                break;
            }
        }
        str[j] = '\0';
    }
    return str;
}