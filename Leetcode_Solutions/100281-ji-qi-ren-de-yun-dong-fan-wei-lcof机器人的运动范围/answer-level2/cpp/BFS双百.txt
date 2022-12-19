### 解题思路
flag:能到达 标记为true，不能到达和到达过的标记为false
每次push进行 ans++ 操作

### 代码

```cpp
int dx[2] = {1,0};
int dy[2] = {0,1};
const int MAXN = 105;
bool flag[MAXN][MAXN];
class Solution {
public:

    int sum_num(int n1,int n2){
        int sums = 0;
        while(n1||n2){
            if(n1) {
                sums += n1%10;
                n1 /= 10;
            }
            if(n2){
                sums += n2%10;
                n2 /= 10;
            }
        }
        return sums;
    }

    int movingCount(int m, int n, int k) {
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                int n = sum_num(i,j);
                if(n <= k) flag[i][j] = true;
                else flag[i][j] = false;
            }
        }

        int ans = 1;

        queue<pair<int,int>> que;while(!que.empty()) que.pop();
        que.push(make_pair(0,0));flag[0][0] = false;

        while(!que.empty()){
            pair cur = que.front();que.pop();
            int x = cur.first, y = cur.second;
            for(int i =0;i<2;i++){
                int nx = x+dx[i],ny = y + dy[i];
                if(nx>=0&&nx<m&&ny>=0&&ny<n&&flag[nx][ny] == true){
                    que.push(make_pair(nx,ny));
                    flag[nx][ny] = false;
                    ans++;
                }
            }
        }
        return ans;
    }
};
```