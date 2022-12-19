# 纯暴力就是DFS,无缓存，超出时间限制
思路，就是遍历每一种移动的次数，然后算出所有可能，
```
int findPaths(int m, int n, int N, int i, int j){
    int sum = 0;
    int k = 0;
    
    for (k = 0; k <= N; k++) {
        sum += getCounr(m-1, n-1,0, i, j, k);
    }  
    
    return sum;
}
//             1,      1  ,    0,      0,      0,       2
int getCounr(int m, int n,int index, int i, int j, int count) {
    if (index == count) {
        if (i < 0 || j < 0 || i > m || j > n) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (i < 0 || j < 0 || i > m || j > n) {
            return 0;
        }
    } 
    return getCounr(m, n, index+1, i, j+1, count) + getCounr(m, n,index+1, i+1, j, count) + getCounr(m, n,index+1, i-1, j, count) + getCounr(m, n,index+1, i, j-1, count);
}
```


