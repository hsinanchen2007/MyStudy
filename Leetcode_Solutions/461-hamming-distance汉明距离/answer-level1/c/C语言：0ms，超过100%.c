```
int hammingDistance(int x, int y){
    int cnt = 0;
    while (x && y){
        cnt += (x % 2) ^ (y % 2);
        //printf("%d %d\n", x % 2, y % 2);
        x /= 2;
        y /= 2;
    }
    while (x){
        if (x % 2 ^ 0)
            cnt++;
        //printf("x = %d\n", x);
        x /= 2;
    }
    while (y){
        if (y % 2 ^ 0)
            cnt++;
        //printf("y = %d\n", y);
        y /= 2;
    }
    return cnt;
}
```
