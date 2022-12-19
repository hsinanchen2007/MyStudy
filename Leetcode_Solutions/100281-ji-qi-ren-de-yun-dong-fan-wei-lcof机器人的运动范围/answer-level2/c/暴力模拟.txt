### 解题思路
广度遍历搜索

### 代码

```c
struct lnode{
    int x;
    int y;
    struct lnode *next;
}lnode;
int b[100][100];
void push(struct lnode *head,int x,int y)
{
    struct lnode *newp=(struct lnode *)malloc (sizeof(struct lnode));
    newp->x=x;
    newp->y=y;
    newp->next=NULL;
    struct lnode *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=newp;
}

int bfs(int m,int n, int k)
{
    int dis[2][2]={{1,0},{0,1}};
    struct lnode *head=(struct lnode*)malloc(sizeof(struct lnode));
    head->next=NULL;
    push(head,0,0);
    while(head->next!=NULL)
    {
        struct lnode *f=head->next;
        for(int i=0;i<2;i++)
        {
            int x=f->x+dis[i][0];
            int y=f->y+dis[i][1];
            if(x<m&&y<n)
            {
                //printf("x:%d   y:%d\n",x,y);
                if(b[x][y]<=k&&b[x][y]!=0)
                {
                    b[x][y]=0;
                    push(head,x,y);
                    //printf("x:%d   y:%d\n",x,y);
                }
            }
        }
        head->next=head->next->next;
    }
    int nums=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==0)
            {
                //printf("i:%d   j:%d\n",i,j);
                nums++;
            }
        }
    }
    return nums;    
}
int movingCount(int m, int n, int k){
    int nums=0;
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[i][j]=i/10+i%10+j%10+j/10;
            if(i==100)
            b[i][j]-=9;
            if(j==100)
            b[i][j]-=9;
            //printf("b[%d][%d]=%d   ",i,j,b[i][j]);
        }
    }
    nums=bfs(m,n,k);
    return nums;
}
```