递归+回溯 用一个nxm的二维数组来表示这个矩形 每一个坐标代表一个1x1的小方格 用1表示已覆盖 用0表示未覆盖 不断检索直至找到第一个未被覆盖的小方格 并看能否扩大 注意不能超出边界 不能与已覆盖的地方形成交集 再递归回溯即可

```
int covered[20][20];
int MIN;
int min(int a,int b)
{if(a<=b) return a;
return b;}
void cover(int n,int m,int s)
{if(s>=MIN) return;
int i,j,k,row,col;
row=-1;
col=-1;
for(i=1;i<=n;i++)
{for(j=1;j<=m;j++)
if(!covered[i][j])
{row=i;
col=j;break;}
if(row>=0) break;}
if(row==-1&&col==-1) {MIN=min(MIN,s);
return;}
for(k=m-col;k>=0;k--)
{if(row+k>n) continue;
int flag=0;
for(i=row;i<=row+k;i++)
{for(j=col;j<=col+k;j++)
if(covered[i][j]) {flag=1;break;}
if(flag) break;}
if(flag) continue;
for(i=row;i<=row+k;i++)
for(j=col;j<=col+k;j++)
covered[i][j]=1; 
cover(n,m,s+1);
for(i=row;i<=row+k;i++)
for(j=col;j<=col+k;j++)
covered[i][j]=0;}
}
 
int tilingRectangle(int n, int m){
if(n==m) return 1;
MIN=169;
cover(n,m,0);
return MIN;
}
 
```
运行结果：
![捕获 - 副本.PNG](https://pic.leetcode-cn.com/f56c6cee14bdfd402620646459577800329236a457dae4ce342eaf0e36e022d8-%E6%8D%95%E8%8E%B7%20-%20%E5%89%AF%E6%9C%AC.PNG)

此外本题还可以用bfs来做 但相比dfs更慢 更费空间 但bfs和dfs思想一样 都是对隐式图（树）的遍历搜索
```
int tilingRectangle(int n, int m){
int i,j,k;
struct Queue{int cover[13][13];int x;int y;int step;}queue[30010];
int front=0;
int rear=1;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
queue[0].cover[i][j]=0;
queue[0].step=0;
while(front<rear)
{int flag=0;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
if(queue[front].cover[i][j]) flag++;
if(flag==n*m) break;
for(i=0;i<n;i++)
{for(j=0;j<m;j++)
if(!queue[front].cover[i][j]) {queue[front].x=i;queue[front].y=j;break;}
if(j<m) break;}
for(k=m-queue[front].y-1;k>=0;k--)  
{if(k+queue[front].x>=n) continue;
struct Queue point;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
point.cover[i][j]=queue[front].cover[i][j];
for(i=queue[front].x;i<=queue[front].x+k;i++)
{for(j=queue[front].y;j<=queue[front].y+k;j++)
{if(!point.cover[i][j]) point.cover[i][j]=1;
else break;}
if(j<=queue[front].y+k) break;}
if(i<=queue[front].x+k) continue;
point.step=queue[front].step+1;
queue[rear]=point;
rear++;}
front++;}
return queue[front].step;
}
```

运行结果：
![捕获 - 副本.PNG](https://pic.leetcode-cn.com/92bd0968820701f7f05b302009e02dacfeb2c7477ef250e7bbb245b65bec617e-%E6%8D%95%E8%8E%B7%20-%20%E5%89%AF%E6%9C%AC.PNG)
