### 解题思路
用链表建立队列
对队列进行bfs
同时记录宽度搜索层数，层数即为距离

### 代码

```c
#include<stdio.h>
#include<stdlib.h>

//定义节点
typedef struct node{
    struct node * next;
    int x;
    int y;
}node;

//定义队列
typedef struct que{
    node* head;
    node* rear;
    int quenumber;
}que;

//初始化队列
que * creatQue(){
    que * q=(que *)malloc(sizeof(que));
    q->head=NULL;
    q->rear=NULL;
    q->quenumber=0;

    return q;
}

//进队
void push(que* q,int x1,int y1){
    node * oneNode = (node *)malloc(sizeof(node));
    oneNode->next=NULL;
    oneNode->x=x1;
    oneNode->y=y1;
    if(q->rear==NULL){
        q->rear=oneNode;
        q->head=oneNode;
        q->quenumber+=1;
    }else{
        q->rear->next=oneNode;
        q->rear=oneNode;
        q->quenumber+=1;
    }


}

//出队
node* pop(que * q){
    if(q->rear==q->head){
        node* oneNode= q->rear;
        q->rear=q->head=NULL;
        q->quenumber=0;
        return oneNode;
    }else{
        node * oneNode=q->head;
        q->head=q->head->next;
        q->quenumber-=1;
        return oneNode;
    }
}

//判断队空
bool isEmpty(que * q){
    return q->head==NULL;
}

//BFS
int bfs(que * q,int ** grid,int *gridColSize,int gridSize){
    int level = -1;
    while(!isEmpty(q)){
        level++;
        int n=q->quenumber;
        for(int i=0;i<n;i++){
            node *oneNode=pop(q);
            if(oneNode->x>0&&grid[oneNode->x-1][oneNode->y]==0){//左
                push(q,(oneNode->x)-1,oneNode->y);
                grid[oneNode->x-1][oneNode->y]=2;
            }
            if(oneNode->x<(gridSize-1)&&grid[oneNode->x+1][oneNode->y]==0){//右
                push(q,(oneNode->x)+1,oneNode->y);
                grid[oneNode->x+1][oneNode->y]=2;
            }
            if(oneNode->y>0&&grid[oneNode->x][oneNode->y-1]==0){//上
                push(q,oneNode->x,oneNode->y-1);
                grid[oneNode->x][oneNode->y-1]=2;
            }
            if(oneNode->y<(gridColSize[oneNode->x]-1)&&grid[oneNode->x][oneNode->y+1]==0){//上
                push(q,oneNode->x,oneNode->y+1);
                grid[oneNode->x][oneNode->y+1]=2;
            }

        }
    }
    return level;

}


int maxDistance(int** grid, int gridSize, int* gridColSize){
    //找出所有的大陆入队
    que * q=creatQue();
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                push(q,i,j);
            }      
        }
    }

    if(isEmpty(q)||q->quenumber==gridSize*gridSize){
        return -1;
    }
    return bfs(q,grid,gridColSize,gridSize);

}
```