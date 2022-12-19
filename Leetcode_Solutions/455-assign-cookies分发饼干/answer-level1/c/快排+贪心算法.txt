### 解题思路
注意一个小朋友只能拿一块饼干的限制，遍历所有饼干s，如果s[j]当前小孩的胃口g[i]，i和j都加1，否则j++
执行用时 :
36 ms
, 在所有 C 提交中击败了
93.31%
的用户
内存消耗 :
7.1 MB
, 在所有 C 提交中击败了
100.00%
的用户
### 代码

```c
int cmpfun(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0;
    int j = 0;

    if(gSize == 0 || sSize == 0){
        return 0;
    }
    qsort(g, gSize, sizeof(int), cmpfun);
    qsort(s, sSize, sizeof(int), cmpfun);

    while(i < gSize && j < sSize){
        if(s[j++] >= g[i]){
            i++;
        }
    }

    return i;
}
```