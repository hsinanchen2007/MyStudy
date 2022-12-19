![20191102-160241(eSpace).png](https://pic.leetcode-cn.com/2e4037729defcd75bf1f23af6bc0bcb7cc9bc9327843cbd1bbf21da4caf9fb39-20191102-160241\(eSpace\).png)


char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0)
        return "";
    else if(strsSize == 1)
        return strs[0];
    
    char *temp;
	temp = (char *)calloc(128, sizeof(char));
    int add = 0;
    int i;
    for(i = 0; i < strlen(strs[0]); i++) {
        for(int j = 1; j < strsSize; j++) {
            if(strs[0][i] == strs[j][i])
                add = 1;
            else {
                add = 0;
                return temp;
            }
        }
        if(add == 1)
            temp[i] = strs[0][i];
    }
    
    return temp;
}
记录一个查找状态，如果状态为1，增加到返回字符串，如果为0，返回已有字符串