### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize == 0 || strs == NULL || strs[0] == NULL){
        return "";
    }    

    if(strsSize == 1){
        return strs[0];
    }
    
    int ret = 0;
    char *des = strs[0];
    char *rr = (char*)malloc(strlen(strs[0]) + 1);
    memset(rr,0,strlen(strs[0]) + 1);

    for(int j = 0; j < strlen(strs[0]);j++){
        for(int i = 1; i < strsSize;i++){
            if(strs[i] == NULL){
                return "";
            }

            if(strlen(strs[i]) < j + 1 || strs[i][j] != strs[0][j]){
                memcpy(rr,strs[0],j);
                return rr;
            }
        }
    }
    
    return strs[0];
}
```