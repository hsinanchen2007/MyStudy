使用的链队记录腐烂橘子的坐标、层数
![image.png](https://pic.leetcode-cn.com/ee0563563cde1e1c54c7edac1558bf14d4ca47d843c0b1db6d3ac5bfb80d9d40-image.png)

```



int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int count[3]={0,0,0};
    int i,j,flag=1;
    struct que{
        int i;
        int j;
        int layer;
        struct que* next;
    };  
    typedef struct que queue;
    queue *head=(queue *)malloc(sizeof(queue));
    queue * q,*tail;
    for(i=0;i<gridSize;i++)
        for(j=0;j<*gridColSize;j++){
            count[grid[i][j]]++;//统计开始的个数            
            if(grid[i][j]==2){
                q=(queue *)malloc(sizeof(queue));
                q->i=i;q->j=j;q->next=head->next;q->layer=0;
                head->next=q;
                if(flag){
                    tail=q;flag=0;q->next=NULL;
                }
            }
        }           
    if(count[1]==0)
        return 0;
    if(count[2]==0)
        return -1;

    int min=0;
    while(1){
        q=head->next;
        queue *ne;
        if(q->i!=0&&grid[(q->i)-1][q->j]==1){//上
            ne=(queue *)malloc(sizeof(queue));
            ne->i=(q->i)-1;ne->j=q->j;ne->layer=q->layer+1;tail->next=ne;tail=ne;tail->next=NULL;
            count[1]--;count[2]++;grid[(q->i)-1][q->j]=2;
        }
        if(q->i!=gridSize-1&&grid[(q->i)+1][q->j]==1){//下
            ne=(queue *)malloc(sizeof(queue));
            ne->i=q->i+1;ne->j=q->j;ne->layer=q->layer+1;tail->next=ne;tail=ne;tail->next=NULL;
            count[1]--;count[2]++;grid[(q->i)+1][q->j]=2;
        }
        if(q->j!=0&&grid[q->i][(q->j)-1]==1){//左
            ne=(queue *)malloc(sizeof(queue));
            ne->i=q->i;ne->j=(q->j)-1;ne->layer=q->layer+1;tail->next=ne;tail=ne;tail->next=NULL;
            count[1]--;count[2]++;grid[q->i][(q->j)-1]=2;
        }
        if(q->j!=*gridColSize-1&&grid[q->i][(q->j)+1]==1){//右
            ne=(queue *)malloc(sizeof(queue));
            ne->i=q->i;ne->j=(q->j)+1;ne->layer=q->layer+1;tail->next=ne;tail=ne;tail->next=NULL;
            count[1]--;count[2]++;grid[q->i][(q->j)+1]=2;
        }
        
        ne=q;q=q->next;head->next=q;
        free(ne);
        if(!q)
            break;
        if(q->layer!=min)
            min+=1;
    }
    if(count[1])
        return -1;
    return min;
}
```