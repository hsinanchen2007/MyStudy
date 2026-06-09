### 解题思路
    哈希 ~ ~ ~
### 代码

```c
int map[128];
int cmp(const void *a,const void *b){
    char ta = *(char *)a;
    char tb = *(char *)b;
    if(map[ta - ' '] == map[tb - ' ']) return ta - tb;
    return map[tb - ' '] - map[ta - ' '];
}

char * frequencySort(char * s){
    int len = strlen(s);
    memset(map,0,sizeof(int) * 128);    
    //' '是ascii值中为0的元素（第一个元素）
    for(int i = 0;i < len;i++) map[s[i] - ' '] ++;
    qsort(s,len,sizeof(char),cmp);
    return s;
}
```