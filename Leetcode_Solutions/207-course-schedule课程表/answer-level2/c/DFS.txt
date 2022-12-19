//DFS - Cycle Detection, 发现VISITING的顶点说明循环。

#define NO_VISITED 0
#define VISITING 1
#define VISITED 2

typedef struct VERTEX{
    int id;
    int state;
    int inNum;
    int outNum;
    int sonNum;
    int sons[100];
} TYPE_VERTEX;

typedef struct GRAPH {
    int vNum;
    int sideNum;
    TYPE_VERTEX v[10000];
    int** side;
} TYPE_GRAPH;



void CalcVertexInfo(TYPE_VERTEX* v, int numCourses, int** prerequisites, int prerequisitesSize)
{
    for (int i = 0; i < numCourses; i++) {
        v[i].id = i;
        v[i].state = NO_VISITED;
        v[i].inNum = 0;
        v[i].outNum = 0;
        v[i].sonNum = 0;
        for (int j = 0; j < prerequisitesSize; j++) {
            if (prerequisites[j][0] == i) {
                v[i].inNum++;
            }
            if (prerequisites[j][1] == i) {
                v[i].outNum++;
                v[i].sons[v[i].sonNum++] = prerequisites[j][0];
            }            
        }
    }
    return;
}


bool IsLeaf(TYPE_GRAPH *g, int vIdx)
{
    return g->v[vIdx].sonNum == 0;
}

//flase表示有循环
bool DFS(TYPE_GRAPH *g, int vIdx) //(Node n, int d)
{
	g->v[vIdx].state = VISITING;
    if (IsLeaf(g, vIdx)) { //一旦搜索深度到达一个结束状态，就返回true
        g->v[vIdx].state = VISITED;
        //printf("%d--%d--%d\n", __LINE__, vIdx, g->v[vIdx].state);
		return true;
	}
 
	for (int i = 0; i < g->v[vIdx].sonNum; i++) { //遍历n相邻的节点nextNode
        int idx = g->v[vIdx].sons[i];
		if (g->v[idx].state == VISITING) { // 说明循环了
            g->v[idx].state = VISITED;
            //printf("%d--%d--%d\n", __LINE__, idx, g->v[idx].state);            
            return false;
        }
		if (DFS(g, idx) == false) { //循环了
            //printf("%d--%d--%d\n", __LINE__, idx, g->v[idx].state);
            return false;
        }
	}
    g->v[vIdx].state = VISITED;
    //printf("%d--%d--%d\n", __LINE__, vIdx, g->v[vIdx].state);    
	return true;
}


void CreateGraph(TYPE_GRAPH *g, int numCourses, int** prerequisites, int prerequisitesSize)
{
    g->vNum = numCourses;
    g->sideNum = prerequisitesSize;
    CalcVertexInfo(g->v, numCourses, prerequisites, prerequisitesSize);
    g->side = prerequisites;
    return;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
    TYPE_GRAPH g;
    CreateGraph(&g, numCourses, prerequisites, prerequisitesSize);

    bool rtn = false;
    for (int i = 0; i < numCourses; i++) {
        if (g.v[i].state == NO_VISITED) {
            rtn = true;
            if (DFS(&g, i) == false) {
                return false;
            }
        }
    }
    return rtn;
}