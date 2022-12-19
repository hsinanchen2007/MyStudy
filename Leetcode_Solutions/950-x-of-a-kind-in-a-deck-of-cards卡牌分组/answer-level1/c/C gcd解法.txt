### 解题思路
此处撰写解题思路

### 代码

```c
int cmpfunc(const void* a, const void* b){
    return ( *(int*)a - *(int*)b );
}
int gcd(int a, int b){
    if(a==0)    return b;
    return gcd(b%a, a);
}
bool hasGroupsSizeX(int* deck, int deckSize){
    qsort(deck, deckSize, sizeof(int), cmpfunc);
    int *res = (int*)malloc(sizeof(int)*(deckSize+1)), index = 0;
    for(int i = 0, count = 0; i < deckSize; i++){
        count++;
        if(i+1==deckSize || deck[i]!=deck[i+1]){
            if(count < 2) return false;
            res[index++] = count;
            count = 0;
        }
    }
    int ans = res[0];
    for(int i = 0; i < index; i++){
        ans = gcd(res[i], ans);
        if(ans == 1)    return false;
    }
    return true;
}
```