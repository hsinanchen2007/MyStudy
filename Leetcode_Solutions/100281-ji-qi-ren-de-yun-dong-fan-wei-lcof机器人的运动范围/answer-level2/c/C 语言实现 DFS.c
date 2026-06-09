```c
static int ans = 0;

int valid(int i,int j,int k){
    int sum = 0;
    int temp = i;
    while(temp != 0){
        sum += temp % 10;
        temp = temp/10;
    }
    temp = j;
    while(temp != 0){
        sum += temp % 10;
        temp = temp/10;
    }
    if(sum > k){
        return 0;
    }
    return 1;
}
void dfs(int i,int j,int m,int n,int k, int record[100][100]){
    // 边界处理返回
    if(i < 0 || j <0 || i >= m || j >= n || record[i][j] == 1){
        return;
    }
    // 缓存遍历过的路径
    record[i][j] = 1;

    // 验证条件
    if(!valid(i,j,k)){
        return;
    }
    ans++;
    // 右
    dfs(i+1,j,m,n,k,record);
    // 左
    dfs(i-1,j,m,n,k,record);
    // 下
    dfs(i,j+1,m,n,k,record);
    // 上
    dfs(i,j-1,m,n,k,record);
}

int movingCount(int m, int n, int k){
    int record[100][100]={0};
    ans = 0;
    dfs(0,0,m,n,k,record);
    return ans;
}
```