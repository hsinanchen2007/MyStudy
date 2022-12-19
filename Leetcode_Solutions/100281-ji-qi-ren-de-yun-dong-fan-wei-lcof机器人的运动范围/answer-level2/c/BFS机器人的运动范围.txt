### 解题思路
    打卡学习 ~ ~ ~
    ps:可以将定义的四个方向（上、下、左、右）改成两个（右、下），即：
    dx[2] = {0,1},dy[2] = {1,0};
    则循环遍历就要改成 : for(int i = 0;i < 2;i++) 
### 代码

```c
//定义节点的结构体
struct point{
    int x;
    int y;
};

//将数字x按位拆分 并 求和
int digitSum(int x){
    int res = 0;
    while(x) res += x % 10,x /= 10;
    return res;
}

int movingCount(int m, int n, int k){
    //若 k == 0
    if(!k) return 1;
    //定义方向
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    //定义辅助数组，判断该格子是否被访问过
    int vis[110][110] = {0};
    //定义结构体数组，存储节点
    struct point q[10010];
    int front = 0,tail = 1,cnt = 0,i,tx,ty;

    //将[0,0]点加入队列
    q[0].x = 0,q[0].y = 0;
    vis[0][0] = 1;

    //循环终止条件：front == tail
    while(front < tail){
        //获取队列头结点，并用front++模拟出队操作（pop操作）
        struct point node = q[front++];
        cnt++;  //每弹出一个节点，计数加1

        //循环遍历上、下、左、右四个方向
        for(i = 0;i < 4;i++){
            tx = node.x + dx[i];
            ty = node.y + dy[i];
            //跳过 不符合条件的格子
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || digitSum(tx) + digitSum(ty) > k)
                continue;
            
            //将符合条件的格子 入队
            q[tail].x = tx;
            q[tail].y = ty;
            tail++;

            //标记被访问过
            vis[tx][ty] = 1;
        }
    }
    return cnt;
}
```