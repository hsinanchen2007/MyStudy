基础bfs
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct
 {
     int x;
     int y;
 }node;
 typedef struct
 {
     node data[20000];
     int rear;
     int front;
 }cqueue;
 cqueue num;
 cqueue*numm=&num;
 node goal;
 node temp;
 int**hash;
 int m,n;
 void push(cqueue*a,node x)
 {
     a->rear++;
     a->data[a->rear]=x;
 }
 void pop(cqueue*a)
 {
     a->front++;
 }
 void empty(cqueue*a)
 {
     a->rear=a->front=-1;
 }
 int isempty(cqueue*a)
 {
     if(a->rear==a->front)
     {
         return 1;
     }
     return 0;
 }
 int judge(node a)
 {
     if(a.x<0||a.x>=m||a.y<0||a.y>=n)
     {
         return 0;
     }
     if(hash[a.x][a.y]==1)
     {
         return 0;
     }
     return 1;
 }
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int i,j;
    int count=0;
    int X[4]={0,-1,0,1};
    int Y[4]={-1,0,1,0};
    m=R;
    n=C;
int**jg=(int**)malloc(sizeof(int*)*(R*C));
int *tmp=(int*)malloc(sizeof(int)*(R*C));
for(i=0;i<R*C;i++)
{
    tmp[i]=2;
    jg[i]=(int*)malloc(sizeof(int)*2);
}
hash=(int**)malloc(sizeof(int*)*(R));
for(i=0;i<R;i++)
{
    hash[i]=(int*)malloc(sizeof(int)*C);
}
for(i=0;i<R;i++)
{
    for(j=0;j<C;j++)
    {
        hash[i][j]=0;
    }
}
*returnSize=R*C;
*returnColumnSizes=tmp;
empty(numm);
goal.x=r0;
goal.y=c0;
jg[count][0]=r0;
jg[count][1]=c0;
count++;
hash[goal.x][goal.y]=1;
push(numm,goal);
while(!isempty(numm))
{
    temp=numm->data[numm->front+1];
    pop(numm);
    for(j=0;j<4;j++)
    {
        goal.x=temp.x+X[j];
        goal.y=temp.y+Y[j];
        if(judge(goal))
        {
            jg[count][0]=goal.x;
            jg[count][1]=goal.y;
            count++;
            hash[goal.x][goal.y]=1;
            push(numm,goal);
        }
    }
}
return jg;
}
```
