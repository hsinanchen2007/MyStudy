空间还可以优化
```
int tribonacci(int n){
    if(n==0){
        return 0;
    }
    if(n>0&&n<=2){
        return 1;
    }
    int *arr = malloc(sizeof(int)*(n+1));
    memset(arr,0,(n+1)*sizeof(int));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    int cnt = 3;
    while(cnt <= n){
        arr[cnt] = arr[cnt-1] + arr[cnt-2] + arr[cnt-3];
        cnt++;
    }
    return arr[n];
}
```
