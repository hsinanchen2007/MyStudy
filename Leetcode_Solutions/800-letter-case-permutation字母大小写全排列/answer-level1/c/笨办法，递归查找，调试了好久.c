### 解题思路
笨办法，递归查找，调试了好久，边界值

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(char *s, char **out, char *tmp, int *size, int len, int tLen)
{
    int sLen = strlen(s);
    int tmpLen = strlen(tmp);
    //printf("in: tmp: %s, S: %s tmplen %d, slen %d size %d\n",tmp,s,tmpLen,sLen,*size);
    if (sLen == 1) {
        if (s[0] >= 'A' && s[0] <= 'Z'){
            out[*size] = (char*)malloc((len+1) * sizeof(char));
            memset(out[*size], 0, (len+1) * sizeof(char));
            tmp[tmpLen] = (s[0] + 32);
            strncpy(out[*size], tmp, len);
            //out[len] = 0;
            (*size)++;

            out[*size] = (char*)malloc((len+1) * sizeof(char));
            memset(out[*size], 0, (len+1) * sizeof(char));
            tmp[tmpLen] = (s[0]);
            strncpy(out[*size], tmp, len);
            //out[len] = 0;
            (*size)++;
        }
        if (s[0] >= 'a') {
            out[*size] = (char*)malloc((len+1) * sizeof(char));
            memset(out[*size], 0, (len+1) * sizeof(char));
            tmp[tmpLen] = (s[0] - 32);
            strncpy(out[*size], tmp, len);
            //out[len] = 0;
            (*size)++;

            out[*size] = (char*)malloc((len+1) * sizeof(char));
            memset(out[*size], 0, (len+1) * sizeof(char));
            tmp[tmpLen] = (s[0]);
            strncpy(out[*size], tmp, len);    
            //out[len] = 0;
            (*size)++;

        }
        if (s[0] <= '9') {
            out[*size] = (char*)malloc((len+1) * sizeof(char));
            memset(out[*size], 0, (len+1) * sizeof(char));
            tmp[tmpLen] = s[0];
            strncpy(out[*size], tmp, len);
            //out[len] = 0;
            (*size)++;
        }
        //printf("out: tmp %s, out %s size %d\n",tmp, out[*size - 1], *size);
    } else {
        if (s[0] <= '9') {
            tmp[tmpLen] = s[0];
            tLen++;
            DFS(s+1, out, tmp, size, len, tLen);
            memset(tmp+tmpLen, 0, len-tmpLen);
        }
        if (s[0] >= 'a') {
            tmp[tmpLen] = s[0];
            tLen++;
            DFS(s+1, out, tmp, size, len, tLen);   
            memset(tmp+tmpLen, 0, len-tmpLen);

            tmp[tmpLen] = (s[0] - 32);
            DFS(s+1, out, tmp, size, len,tLen);
            memset(tmp+tmpLen, 0, len-tmpLen);
        }
        if (s[0] >= 'A' && s[0] <= 'Z') {
            tmp[tmpLen] = s[0];
            tLen++;
            DFS(s+1, out, tmp, size, len,tLen);
            memset(tmp+tmpLen, 0, len-tmpLen);

            tmp[tmpLen] = (s[0] + 32);
            DFS(s+1, out, tmp, size, len,tLen);
            memset(tmp+tmpLen, 0, len-tmpLen);
        }
    }
    //printf("out final %s \n",out[*size-1]);
    return;
}

char ** letterCasePermutation(char * S, int* returnSize){
    char **out = NULL;
    int sLen = strlen(S);
    char *tmpArr = NULL;
    int tLen = 0;
    
    *returnSize = 0;
    if (sLen < 1) {
        return NULL;
    }

    out = (char**)malloc(50000 * sizeof(char));
    memset(out, 0, 50000 * sizeof(char));
    tmpArr = (char*)malloc((sLen+1) * sizeof(char));
    memset(tmpArr, 0, (sLen+1) * sizeof(char));

    DFS(S, out, tmpArr, returnSize, sLen, tLen);
    //printf("end ");
    return out;
}
```