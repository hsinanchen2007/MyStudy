### 解题思路
有根树三个特点：
（1）只有根节点入度为0；
（2）除根节点外所有结点的入度为1；
（3）从根节点出发可以到达任意后继结点。
先写一个算法判断（1）和（2）是否满足，再利用拓扑排序算法判断是否满足特点（3），顺序不可逆。
复杂度暂不追求。。。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXVEX 1001

typedef struct EdgeNode{
    int adjvex;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode{
    int indegree;
    int outdegree;
    int data;
    EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct{
    AdjList adjList;
    int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

void CreateGraph(GraphAdjList G, int nVertexes, int** Edges, int nEdges, int add);
bool TopoSort(GraphAdjList GL);
bool IsTree(GraphAdjList GL);

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    //构造nums
    *returnSize = 2;
    int* nums;
    nums = (int *)malloc(sizeof(int) * MAXVEX);
    int* addedge;
    addedge = (int *)malloc(sizeof(int) * 2);
    int i;
    for(i=0; i<MAXVEX; i++)
        nums[i] = i+1;
    //自后向前依次去除一条边
    for(i=edgesSize-1; i>=0; i--){
        GraphAdjList GL;
        GL = (graphAdjList *)malloc(sizeof(graphAdjList));
        CreateGraph(GL, MAXVEX, edges, edgesSize, i);
        if( IsTree(GL) && TopoSort(GL) ){
            addedge[0] = edges[i][0];
            addedge[1] = edges[i][1];
            return addedge;
        }
        free(GL);
    }
    return NULL;
}

void CreateGraph(GraphAdjList G, int nVertexes, int** Edges, int nEdges, int add){
    int i, j, k;
    EdgeNode *e;
    G->numVertexes = nVertexes;
    G->numEdges = nEdges;
    for(i=0; i<G->numVertexes; i++){ //读取顶点信息，建立顶点表
        G->adjList[i].data = i;
        G->adjList[i].indegree = 0;
        G->adjList[i].outdegree = 0;
        G->adjList[i].firstedge = NULL;
        //printf("G->adjList[%d]= %d\n", i, G->adjList[i].data);
    }
    for(k=0; k<G->numEdges; k++){ //建立边表
        if(k == add)
            continue;
        i = Edges[k][0]; //弧尾
        j = Edges[k][1]; //弧头
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        G->adjList[j].indegree++;
        G->adjList[i].outdegree++;
    }
}

bool TopoSort(GraphAdjList GL){
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
        count++; //统计存入个数
        for(e=GL->adjList[gettop].firstedge; e; e=e->next){ //遍历以此顶点为弧尾的弧
            k = e->adjvex;
            if( ! (--GL->adjList[k].indegree) ) //将k号顶点邻接点的入度减1
                stack[++top] = k; //若该邻接点的入度为0，则入栈
        }
    }
    if(count < GL->numVertexes)
        return false;
    return true;
}

bool IsTree(GraphAdjList GL){
    int i, m=0, n=0, r=0;
    for(i=0; i<GL->numVertexes; i++){
        if(GL->adjList[i].indegree == 0 && GL->adjList[i].outdegree != 0)
            m++; //跟（入度为0，出度部位0）的个数
        if(GL->adjList[i].indegree == 1)
            n++; //根外节点（入度为1）的个数
        if(GL->adjList[i].indegree == 0 && GL->adjList[i].outdegree == 0)
            r++; //冗余结点（入度=出度=0）的个数
    }
    if( m==1 && n == (GL->numVertexes - r - 1) )
        return true;
    return false;
}

```