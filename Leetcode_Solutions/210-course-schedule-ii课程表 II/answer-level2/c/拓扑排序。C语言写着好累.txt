### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXVEX 10000

typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    int indegree;
    int data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
    AdjList adjList;
    int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

void CreateGraph(GraphAdjList G, int nVertexes, int** Edges, int nEdges);
bool TopoSort(GraphAdjList GL, int* nums, int numsSize);

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    *returnSize = numCourses;
    if(numCourses == 0)
        return NULL;
    int* coursesorder = malloc(sizeof(int) * MAXVEX);
    if(numCourses == 1){
        coursesorder[0] = 0;
        return coursesorder;
    }
    if(prerequisitesSize == 0){
        for(int i=0; i<numCourses; i++)
            coursesorder[i] = i;
        return coursesorder;
    }
    if(prerequisitesSize == 1){
        coursesorder[0] = prerequisites[0][1];
        coursesorder[1] = prerequisites[0][0];
        int j = 2;
        if( numCourses > 2 ){
            for(int i=0; i<numCourses; i++){
                if(i == coursesorder[0] || i == coursesorder[1])
                    continue;
                coursesorder[j] = i;
                j++;
            }
        }
        return coursesorder;
    }
    GraphAdjList GL;
    GL = (graphAdjList *)malloc(sizeof(graphAdjList));
    CreateGraph(GL, numCourses, prerequisites, prerequisitesSize);
    //printf("(GL->adjList[1].firstedge)->adjvex = %d\n", (GL->adjList[1].firstedge)->adjvex);
    if( TopoSort(GL, coursesorder, numCourses) )
        return coursesorder;
    *returnSize = 0;
    return coursesorder;
}

void CreateGraph(GraphAdjList G, int nVertexes, int** Edges, int nEdges){
    int i, j, k;
    EdgeNode *e;
    G->numVertexes = nVertexes;
    G->numEdges = nEdges;
    for(i=0; i<G->numVertexes; i++){ //读取顶点信息，建立顶点表
        G->adjList[i].data = i;
        G->adjList[i].indegree = 0;
        G->adjList[i].firstedge = NULL;
        //printf("G->adjList[%d]= %d\n", i, G->adjList[i].data);
    }
    for(k=0; k<G->numEdges; k++){ //建立边表
        i = Edges[k][0]; //弧头
        j = Edges[k][1]; //弧尾
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
        G->adjList[i].indegree++;
        //printf("(G->adjList[%d].firstedge)->adjvex = %d\n", j, (G->adjList[j].firstedge)->adjvex);
    }
}

bool TopoSort(GraphAdjList GL, int* nums, int numsSize){
    EdgeNode *e;
    int i, k, gettop;
    int top = 0; //栈下标
    int count = 0; //统计存入nums顶点的个数
    int *stack; //建栈存储入度为0的顶点
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0; i<GL->numVertexes; i++)
        if(GL->adjList[i].indegree == 0)
            stack[++top] = i; //入栈
    while(top != 0){
        gettop = stack[top--]; //出栈
        nums[count] = GL->adjList[gettop].data; //存入数组
        //printf("nums[%d] = %d\n", count, nums[count]);
        count++; //统计存入个数
        for(e=GL->adjList[gettop].firstedge; e; e=e->next){ //遍历以此顶点为弧尾的弧
            k = e->adjvex;
            if( ! (--GL->adjList[k].indegree) ) //将k号顶点邻接点的入度减1
                stack[++top] = k; //若该邻接点的入度为0，则入栈
        }
    }
    if(count < GL->numVertexes)
        return false;
    else
        return true;
}

```