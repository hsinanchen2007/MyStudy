### 解题思路
DFS C语言实现，好像效率和内存占有都有点高啊 求大神指导

### 代码

```c
char * appendString(char* dst,char *src1)
{
    return strcat(dst,src1);
}
char * allocString(int size){
    return (char *)calloc(size+1, sizeof(char));
}
void freeString(char * ptr){
    free(ptr);
}
//alloc inside funciton
char ** pushString (char * ptr,int *cnt, int init){
    static int count = 0;
    static  char ** link = NULL;
    if(init ==1){
        count = 0;
        link = NULL;
        return;
    }
    if(ptr!=NULL){
        count ++;
        link =  realloc(link, (count+1) * sizeof (char *));
        link[count] = NULL;
        link[count-1] = ptr;//allocString(2*n); //free outside 
    }
    if(cnt)
        *cnt = count;
    return link;
}

char *allocCombinedString(char* pStr1, char*pStr2,int size){
        char * ret = allocString(2*size); //free outside 
        appendString(ret,pStr1);
        appendString(ret,pStr2);
        return ret;
}
void find (char * tmpStr, char * appendStr, int lCnt, int rCnt, int size){
    if(lCnt > size || rCnt > size|| rCnt>lCnt)
        return ;
    if(lCnt == size && rCnt == size){
        pushString(allocCombinedString(tmpStr,appendStr,size),NULL,0);
        return;
    }
    char * tmp = allocCombinedString(tmpStr,appendStr,size);
    find(tmp,"(",lCnt+1,rCnt,size);
    find(tmp,")",lCnt,rCnt+1,size);
    freeString(tmp);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    char **ret;
    pushString(0,0,1);
    find("","",0,0,n);
    ret =pushString(0,returnSize,0);
    return ret;
}
```