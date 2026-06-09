首先判断有没有两个父亲的情况：
  有两个父亲，先删除后出现的边，看一下剩下的关系会不会构成一个圈；不会构成一个圈，直接返回当前边；
             会构成一个圈，就删除另外一个父亲的边；
  没有两个父亲，并查集找最后出现的构成圈的边；

 并查集主要有两步：合并结点对应的根结点；查找结点的根节点；所有的操作都基于根节点进行即可；


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 1001
int g_root[MAX];//根结点
int g_pre[MAX];//父节点
int g_relation[MAX];//输入的关系idx

int findRoot(int x)
{
    while(x != g_root[x]) {
        x = g_root[x];        
    }
    return x;
}

void unioNode(int x, int y)
{
	x = findRoot(x);
    y = findRoot(y);

    if ( g_root[y] >=  g_root[x]) {
        g_root[y]= x;
    } else {
        g_root[x]= y;
    }    
}

int judgeCycle(int** edges, int edgesSize, int ignoreIdx)
{
    int i;
    for (i = 0; i < edgesSize; i++) {
        if (i == ignoreIdx){
            continue;
        }
        //如果两个结点已经连接，则返回i        
        if (findRoot(edges[i][0]) == findRoot(edges[i][1])) {
            return i;
        } else {//如果两个节点没有连接，则连接在一起
            unioNode(edges[i][0],edges[i][1]);
        }
    }

    return i;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int i;
    int idx = -1;
    int rslt;

    for (i = 0; i < MAX; i++) {
        g_root[i] = i;
        g_pre[i] = 0;
        g_relation[i] = 0;
    }

    *returnSize = 2;

    for (i = 0; i < edgesSize; i++) {
        if(g_pre[edges[i][1]] == 0) {
            g_pre[edges[i][1]] = edges[i][0];
            g_relation[edges[i][1]] = i;
        } else {//已经出现过一个父节点，一定在这个出现过两次父节点的关系里
            idx = i;
            rslt = judgeCycle(edges, edgesSize, idx);
            //如果是提前退出，则证明找到一个环形，那么需要删除的是另外一条关系
            if (edgesSize > rslt) {
                idx = g_relation[edges[i][1]];
            } 
            return &edges[idx][0];
        }
    }

    //没有出现两个父节点的情况，则直接找环形，找到环形删除即可
    rslt = judgeCycle(edges, edgesSize, idx);

    return  &edges[rslt][0];
    

}
