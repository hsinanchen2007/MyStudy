#define MAX 1001
int g_root[MAX];//根结点

int FindRoot(int num) {
    //只有根节点是自己的时候，才是真正的根节点
    while(g_root[num] != num) {
        num = g_root[num];
    }
    return num;
}


void unioNode(int x, int y)
{
    /* 这一步一定是对根节点做操作，只要所有的处理都基于根节点做处理，
      子节点的关系跟从根节点即可 */
	x = FindRoot(x);
    y = FindRoot(y);

    if ( g_root[y] >=  g_root[x]) {
        g_root[y]= x;
    } else {
        g_root[x]= y;
    }    
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int i;
    for (i = 0; i < MAX; i++) {
        g_root[i] = i;
    }

    *returnSize = 2;

    for (i = 0; i < edgesSize; i++) {
        //如果两个结点已经连接，则认为这个关系是多余的，返回这一条关系        
        if (FindRoot(edges[i][0]) == FindRoot(edges[i][1])) {
            return &edges[i][0];
        } else {//如果两个节点没有连接，则连接在一起
            unioNode(edges[i][0],edges[i][1]);
        }
    }

    return &edges[edgesSize -1][0];
}