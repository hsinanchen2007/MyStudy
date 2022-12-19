```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char flip(char c) {
    if(c>='a' && c<='z')
        return c-32;
    else
        return c+32;
}
char ** letterCasePermutation(char * S, int* returnSize){
    *returnSize = 0;
    char** ret=malloc(4096*sizeof(char*));
    ret[0] = malloc(13*sizeof(char));
    void dfs(char * S, int idx) {
        //printf("x: %d y: %d %c\n",*returnSize, idx,S[idx]);
        if(S[idx]=='\0') {
            ret[*returnSize][idx]=S[idx];
            return;
        }
        ret[*returnSize][idx]=S[idx];
        dfs(S, idx+1);
        if(S[idx]<'0' || S[idx]>'9') {
            (*returnSize)++;
            ret[*returnSize] = malloc(13*sizeof(char));
            memcpy(ret[*returnSize], ret[(*returnSize)-1], idx*sizeof(char));
            ret[*returnSize][idx]=flip(S[idx]);
            dfs(S, idx+1);
        }
    }
    dfs(S, 0);
    (*returnSize)++;
    return ret;
}
```
