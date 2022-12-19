### 解题思路
建立邻接表
顶点节点里加入flag,判断其是否被遍历过
用队列存储入度为0的顶点

### 代码

```c
struct Node{
    int innum;
    int outnum;
    int scan;
    int *outlist;
};

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    struct Node vecs[numCourses];
    int i=0;
    for(i;i<numCourses;i++){//初始化顶点数组
        vecs[i].innum=0;
        vecs[i].outnum=0;
        vecs[i].scan=0;
    }
    i=0;
    while(i<prerequisitesSize){ //建立邻接表
        vecs[prerequisites[i][0]].innum++;
        vecs[prerequisites[i][1]].outnum++;
        if(vecs[prerequisites[i][1]].outnum==1)
            vecs[prerequisites[i][1]].outlist=(int *)malloc(sizeof(int));
        else
            vecs[prerequisites[i][1]].outlist=(int *)realloc(vecs[prerequisites[i][1]].outlist,sizeof(int)*vecs[prerequisites[i][1]].outnum);
        vecs[prerequisites[i][1]].outlist[vecs[prerequisites[i][1]].outnum-1]=prerequisites[i][0];
        i++;
    }
    int queue[numCourses];
    int front=0,rear=0;
    
    for(i=0;i<numCourses;i++)   ///入度为0的进入
        if(vecs[i].innum==0)
            queue[rear++]=i;
    

    while(front!=rear){
        i=vecs[queue[front]].outnum;

        while(i>0){            
            if(--vecs[vecs[queue[front]].outlist[i-1]].innum==0)
                queue[rear++]=vecs[queue[front]].outlist[i-1];//入队
            i--;
        }
        printf("%d x",queue[front]);
        vecs[queue[front]].scan=1;
        front++;//出队
    }
    for(i=0;i<numCourses;i++)
        if(vecs[i].scan==0)
            return false;

    return true;
}
```