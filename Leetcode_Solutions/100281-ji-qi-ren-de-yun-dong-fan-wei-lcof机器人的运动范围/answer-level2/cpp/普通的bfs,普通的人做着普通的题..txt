### 解题思路
此处撰写解题思路

### 代码


```cpp
int xx[4]={0,1}; 
int yy[4]={1,0};
/*同时这道题还有一个隐藏的优化：我们在搜索的过程中搜索方向可以缩减为向右和向下，而不必再向上和向左进行搜索。如下图，我们展示了 16 * 16 的地图随着限制条件 k 的放大，可行方格的变化趋势，每个格子里的值为行坐标和列坐标的数位之和，蓝色方格代表非障碍方格，即其值小于等于当前的限制条件 k。我们可以发现随着限制条件 k 的增大，(0, 0) 所在的蓝色方格区域内新加入的非障碍方格都可以由上方或左方的格子移动一步得到。而其他不连通的蓝色方格区域会随着 k 的增大而连通，且连通的时候也是由上方或左方的格子移动一步得到，因此我们可以将我们的搜索方向缩减为向右或向下。--详情看官方题解*/

bool vis[1000][1000];
struct node{
    int x,y;
};
class Solution {
public:
    int The_sum_of_digits(int n){
        int sum = 0;
        while(n){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int movingCount(int m, int n, int k) {
        memset(vis,false,sizeof vis);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int temp = The_sum_of_digits(i)+The_sum_of_digits(j);
                if(temp<=k){
                    vis[i][j]=true;
                }
            }
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        queue<node> q;
        while(!q.empty()){
            q.pop();
        }
        struct node temp;
        temp.x = 0;
        temp.y = 0;
        vis[temp.x][temp.y] = false;
        q.push(temp);
        int ret = 1;
        while(!q.empty()){
            struct node temp = q.front();
            q.pop();
            for(int i = 0;i<4;i++){
                struct node tem;
                tem.x =temp.x + xx[i];
                tem.y =temp.y + yy[i];
                if(tem.x>=0 && tem.x<m && tem.y>=0 && tem.y<n && vis[tem.x][tem.y]){
                    vis[tem.x][tem.y] = false;
                    ret++;
                    q.push(tem);
                }
            }
        }
        return ret;
    }
};
```