    char * longestCommonPrefix(char ** strs, int strsSize){
        if (strsSize == 0) {
            char* res = "";
            return res;	
        }
        char* common = strs[0];
        for (int i = 1; i < strsSize; i ++) {
            int j = 0;
            while (common[j] == strs[i][j] && common[j] != '\0') {
                j ++;
            }
            common[j] = '\0';
        }
        return common;
    }