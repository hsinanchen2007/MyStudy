### 解题思路
为了避免重复计算，咱们先在最开始的时候把每个点对应的数位和求出来。
然后就是DFS对四个方向进行搜索，然后判断边界条件。
边界条件：
只要是图搜索就一定有的边界有三个:
- 行数在0~m
- 列数在0~n
- 该节点没有访问过
此题还有一个数位和<k，也就是当前坐标的值<k

最后在深搜过程中设置一个计数变量即可（计数基础值为1，最终值是当前值+子问题值）
### 代码

```cpp
class Solution {
public:
    const static int N = 110;
    int grid[N][N];
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int dig_sum(int num){
        int n=0;
        while(num){
            int res = num%10;
            num/=10;
            n+=res;
        }
        return n;
    }
    int dfs(int m, int n, int x, int y, int k){
        
        int cnt = 1;
        grid[x][y] = -1;
        for(int i = 0;i < 4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < m && nx >= 0 && ny < n && ny >= 0&&grid[nx][ny] <= k&&grid[nx][ny] != -1){
               // printf("%d%d%d%d\n",nx,ny,m,n); 
                cnt += dfs(m,n,nx,ny,k);
            }
        }
        return cnt;
    }
    int movingCount(int m, int n, int k) {
        int p=0;
        for(int i = 0;i < m;i++){
            for(int j = 0; j<n;j++){
                int tmp = dig_sum(i)+dig_sum(j);
                grid[i][j] = tmp;
            }
        }
        int res = dfs(m,n,0,0,k);
        return res;
    }
};
```