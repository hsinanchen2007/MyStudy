### 解题思路
此处撰写解题思路

### 代码

```c
void count_next(char *needle,int *next){
    next[0]=-1;
    if(strlen(needle)==1)
        return;
    next[1]=0;
    for(int i=2;i<strlen(needle);i++){
        int k=next[i-1];
        while(k!=-1&&needle[i-1]!=needle[k]){
            k=next[k];
        }
        next[i]=k+1;
    }
}


int strStr(char * haystack, char * needle){
    if(strlen(needle)==0)
        return 0;
    int next[strlen(needle)],i,j;
    count_next(needle,next);
    for(i=0,j=0;i<strlen(haystack);){
        while(haystack[i]!=needle[j]){
            j=next[j];
            if(j==-1)
                break;
        }
        if(j==-1)
        {
            i++;j++;continue;
        }else {
            if(j==strlen(needle)-1) return i-j;
            i++;j++;continue;
        }
    }
    return -1;
}
```