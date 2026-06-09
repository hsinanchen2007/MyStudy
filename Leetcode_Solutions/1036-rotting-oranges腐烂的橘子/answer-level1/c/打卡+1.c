### 解题思路
此处撰写解题思路

### 代码

```c

typedef struct point{
    int x,y;
    int d;
}Node;

#define LEN 0xffff

int get(int** arr,int m,int n,int total)
{
    Node qu[LEN],*node;
    int head=0,rear=0,i,x,y,j,last=0;
    int xs[]={-1,0,0,1};
    int ys[]={0,-1,1,0};

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==2)
            {
                qu[head].x=i;
                qu[head].y=j;
                qu[head++].d=0;
            }
        }
    }

    if(total==0)return 0;

    while(rear<head)
    {
        node=&qu[rear++];

        if(total<=0)return last;

        for(i=0;i<4;i++)
        {
            x=node->x+xs[i];
            y=node->y+ys[i];
            if(x>=0&&x<m&&y>=0&&y<n&&arr[x][y]==1)
            {
                qu[head].x=x;
                qu[head].y=y;
                qu[head++].d=node->d+1;
                last=node->d+1;
                total--;
                arr[x][y]=2;
            }
        }
    }

    return -1;
}


int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int n=gridColSize[0];
    int i,j,total=0;

    for(i=0;i<gridSize;i++)
    {
        for(j=0;j<n;j++)
        {
            if(grid[i][j]==1)
                total++;
        }
    }

    return get(grid,gridSize,n,total);
}
```