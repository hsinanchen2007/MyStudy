按位异或
```
int hammingDistance(int x, int y){
    int cnt = 0, n = 32;
    while(n--){
        if((x & 1) ^ (y & 1))
            cnt++;
        x >>= 1;
        y >>= 1;
    }
    return cnt;
}
```