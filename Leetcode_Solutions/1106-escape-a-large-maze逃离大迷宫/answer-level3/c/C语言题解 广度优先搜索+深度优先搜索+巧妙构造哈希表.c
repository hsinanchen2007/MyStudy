由于0 <= blocked.length <= 200
故存在一个400x400的范围 
1.从源点出发可能在这个范围内可到达终点
2.如果从源点出发跳出了这个范围且从终点出发跳出了这个范围 则从源点出发必能到达终点
搜索两次
第一次搜索从源点出发 分两种情况
1.到达终点 则返回true
2.跳出范围 进行第二次搜索
3.不能跳出范围 则返回false
由于可能在范围内就到达终点 故第一次搜索用广度优先搜索
第二次搜索从终点出发 如果跳出范围 返回true
否则返回false
两次搜索最多搜索32万次
但对于走过的点要做标记
最好的方法莫过于设立一个标记数组vis[i][j]
但此题范围过大 在不离散化的前提下无法开这种数组
故可采用哈希表做标记
坐标x y最早设立的键值是x+y
尔后发现重复现象过多
导致哈希查找上花了大量时间
所谓键值x+y重复现象过多的本质是在一个400x400的坐标中直线x+y=k上有多少个整数对
x+y=k是直线 所以会存在多个整数对 在x+y=400这条直线上可找出400个整数对 所以会在哈希查找上花费大量时间
不妨把键值设立为曲线
这里设立的是一个圆
即把坐标x y的键值设立为xx+yy
曲线上的整数对大大减少 故而可减少浪费在哈希查找上的时间

完整代码如下
```
bool FLAG[2];
int mod;
struct HASH{int x;int y;struct HASH* next;}hash[160001];
void init()
{for(int i=0;i<160001;i++)
hash[i].next=NULL;}
int hashed(int x,int y)
{long long xx=x;
long long yy=y;
long long num=xx*xx+yy*yy;
if(num==0) return 0;
return num%160001;}
void create(int x,int y)
{int temp=hashed(x,y);
struct HASH *p=(struct HASH*)malloc(sizeof(struct HASH));
p->x=x;
p->y=y;
p->next=hash[temp].next;
hash[temp].next=p;}
bool search(int x,int y)
{int temp=hashed(x,y);
struct HASH *p=hash[temp].next;
int s=0;
while(p)
{if(p->x==x&&p->y==y) return false;
p=p->next;}
return true;}
 
void dfs(int x,int y,int xx,int yy,int xxx,int yyy,int n)
{if(FLAG[n]==true) return;
if(x>0&&search(x-1,y)==true) {if(abs(x-1-xx)+abs(y-yy)>=200) FLAG[n]=true;else {create(x-1,y);dfs(x-1,y,xx,yy,xxx,yyy,n);}}
if(x<mod&&search(x+1,y)==true) {if(abs(x+1-xx)+abs(y-yy)>=200) FLAG[n]=true;else {create(x+1,y);dfs(x+1,y,xx,yy,xxx,yyy,n);}}
if(y>0&&search(x,y-1)==true) {if(abs(x-xx)+abs(y-1-yy)>=200) FLAG[n]=true;else {create(x,y-1);dfs(x,y-1,xx,yy,xxx,yyy,n);}}
if(y<mod&&search(x,y+1)==true) {if(abs(x-xx)+abs(y+1-yy)>=200) FLAG[n]=true;else {create(x,y+1);dfs(x,y+1,xx,yy,xxx,yyy,n);}}
}


bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize){
mod=999999;
FLAG[0]=false;
FLAG[1]=false;
init();
for(int i=0;i<blockedSize;i++)
create(blocked[i][0],blocked[i][1]);
struct Queue{int x;int y;}queue[160001];
int front=0;
int rear=1;
queue[0].x=source[0];
queue[0].y=source[1];
int xx=source[0];
int yy=source[1];
int op[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
create(queue[0].x,queue[0].y);
while(front<rear)
{if(queue[front].x==target[0]&&queue[front].y==target[1]) return true;
for(int i=0;i<4;i++)
{struct Queue point;
point.x=queue[front].x+op[i][0];
point.y=queue[front].y+op[i][1];
if(point.x>=0&&point.x<=mod&&point.y>=0&&point.y<=mod&&search(point.x,point.y)==true)
{if(abs(point.x-xx)+abs(point.y-yy)>=200) {FLAG[0]=true;continue;}
create(point.x,point.y);
queue[rear]=point;
rear++;}}
front++;}
init();
for(int i=0;i<blockedSize;i++)
create(blocked[i][0],blocked[i][1]);
if(FLAG[0]==false) return FLAG[0];
dfs(target[0],target[1],target[0],target[1],source[0],source[1],1);
return FLAG[1];
}


```
运行结果:
![捕获3.PNG](https://pic.leetcode-cn.com/e9d6f9a20a31e59e6b4bdb683f11bbe962dc5c04f7fc532abc572dfd6c01420b-%E6%8D%95%E8%8E%B73.PNG)
哈希键值优化前的运行结果：
![捕获5.PNG](https://pic.leetcode-cn.com/c9ba56b1de098d8a0029ceb37ec001c1e2902f5ca05e744d688b4dbede90ee7b-%E6%8D%95%E8%8E%B75.PNG)

时间复杂度：由于哈希查找仍存在大量重复，故时间复杂度很难估算
空间复杂度:16000个单位