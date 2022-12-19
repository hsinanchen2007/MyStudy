### 解题思路
遍历地图搜索“大陆图”+DFS“大陆图”+统计
DFS的时候，做标记：把搜索过的大陆位置改成0即可

### 代码

```c
//栈节点
typedef struct Node{
    int row;
    int col;
    struct Node* next;
}Node;
//新建节点
Node* newNode(int Row,int Col)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->row=Row;
    n->col=Col;
    n->next=0;
    return n;
}
//入栈
void push(Node* Head,int Row,int Col)
{
    Node* n=newNode(Row,Col);
    n->next=Head->next;
    Head->next=n;
}
//出栈
void pop(Node* Head,int* OutRow,int* OutCol)
{
    Node* del=Head->next;
    Head->next=del->next;
    *OutRow=del->row;
    *OutCol=del->col;
    free(del);
}
//释放栈内存
void delStack(Node* Head)
{
    while(Head!=0)
    {
        Node* del=Head;
        Head=Head->next;
        free(del);
    }
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int MaxArea=0;//最大面积
    Node* stack=newNode(-1,-1);//空栈
    //遍历地图，搜索陆地的坐标
    for(int row=0;row<gridSize;++row)
        for(int col=0;col<gridColSize[row];++col)
            if(grid[row][col]!=0)
            {
                int area=0;//当前陆地面积
                push(stack,row,col);//陆地坐标入栈
                grid[row][col]=0;//注意：入栈之后马上标记，不能等出栈的时候再标记，不然会有同一坐标重复入栈的现象
                while(stack->next!=0)
                {
                    int landRow,landCol;//栈顶陆地坐标
                    pop(stack,&landRow,&landCol);
                    ++area;//当前陆地面积+1
                    //搜索当前坐标的右下左上位置有没有陆地，有则入栈+标记
                    if(landCol+1<gridColSize[landRow]&&grid[landRow][landCol+1]==1)
                    {
                        push(stack,landRow,landCol+1); 
                        grid[landRow][landCol+1]=0;
                    }
                    if(landRow+1<gridSize&&grid[landRow+1][landCol]==1)
                    {
                        push(stack,landRow+1,landCol);
                        grid[landRow+1][landCol]=0;                        
                    }
                    if(landCol-1>=0&&grid[landRow][landCol-1]==1)
                    {
                        push(stack,landRow,landCol-1);   
                        grid[landRow][landCol-1]=0;                    
                    }
                    if(landRow-1>=0&&grid[landRow-1][landCol]==1)
                    {
                        push(stack,landRow-1,landCol);      
                        grid[landRow-1][landCol]=0;                  
                    }
                }
                MaxArea=MaxArea>area?MaxArea:area;//最大面积和当前陆地面积比较，更新最大面积
            }
        delStack(stack);
    return MaxArea;
}
```