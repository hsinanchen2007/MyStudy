该问题转换为寻找树的最小高度；
1、计算所有节点的度；
2、使用BFS删除同一层度为1的节点（即叶子节点）；每层level加1；
3、删除到最后如果只有1个节点，树的高度（level - 1），直径为 2 *（level - 1）；
4、最后没有节点树的高度level，直径为2 * level - 1;


```
#define MAXQUELEN 10010
int *g_degree = NULL;
int *g_queue = NULL;
int g_tail = 0;
int g_head = 0;

void AddQue(int id)
{
    g_queue[g_tail++] = id;
    return;
}

void DelQue(int *id)
{
     *id = g_queue[g_head++];
    return;
}

void DelDegree(int** edges, int edgesSize,int id)
{
    for (int i = 0; i < edgesSize; i++) {
       if( edges[i][0] == id ) {
            g_degree[edges[i][1]]--;
            if(g_degree[edges[i][1]] == 1) {
                 AddQue(edges[i][1]);
            }
       }
       if(edges[i][1] == id ) {
           g_degree[edges[i][0]]--;
            if(g_degree[edges[i][0]] == 1) {
                 AddQue(edges[i][0]);
            }
       }
    }
    return;

}

int treeDiameter(int** edges, int edgesSize, int* edgesColSize){
    int id = 0;
    int level = 0;
    int flag = 0;
    if (edgesSize == 0) {
        return 0;
    }
    g_tail = 0;
    g_head = 0;
    g_queue = malloc(sizeof(int) * MAXQUELEN);
    g_degree = malloc(sizeof(int) * (edgesSize * 2));

    memset(g_degree,0,sizeof(int) * (edgesSize * 2));
    for (int i = 0; i < edgesSize; i++) {
        g_degree[edges[i][0]]++;
        g_degree[edges[i][1]]++;
    }
    for (int i = 0; i < (edgesSize * 2); i++) {
        if(g_degree[i] == 1) {  
            AddQue(i);
        }
    }
    while (g_tail > g_head) {
        int num = g_tail - g_head;
        level++;
        if (num == 1) {
            flag = 1;
        }
        for (int i = 0; i < num; i++) {
            DelQue(&id);
            DelDegree(edges, edgesSize, id);
        }
    }
    int res = 0;
    if(flag == 1) {
        res = 2 * (level - 1);
    }else{
        res = 2 * level - 1;
    }
    free(g_queue);
    free(g_degree);
    return res;
}
```
