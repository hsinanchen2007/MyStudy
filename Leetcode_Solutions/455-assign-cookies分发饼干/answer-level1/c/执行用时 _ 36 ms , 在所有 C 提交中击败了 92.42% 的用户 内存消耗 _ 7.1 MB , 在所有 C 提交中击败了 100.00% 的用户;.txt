### 解题思路
此处撰写解题思路

### 代码

```c

int cmp(void *a,void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;  
    return *p1 - *p2;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    if (!g || gSize <= 0 || !s || sSize <= 0) {
        return 0;
    }
    qsort(g,gSize,sizeof(int),cmp);
    qsort(s,sSize,sizeof(int),cmp);

    int iContentNum = 0;
    int iPos = 0;
    int i,j;
    //胃口值gi  饼干尺寸sj
    for(i = 0; i < gSize; i++){
        for(j = iPos; j < sSize; j++){
            if(s[j] >= g[i]){
                iContentNum++;
                iPos = j+1;
                break;
            } 
        }
        if(iPos == j)return iContentNum;
    }
    iContentNum = (iContentNum > gSize)?gSize:iContentNum;
    return iContentNum;
}
```