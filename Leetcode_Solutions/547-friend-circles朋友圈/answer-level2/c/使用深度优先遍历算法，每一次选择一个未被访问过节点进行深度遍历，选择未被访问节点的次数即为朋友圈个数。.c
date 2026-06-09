
每次选择1个未被访问的节点，然后使用深度优先算法进行遍历，如果能遍历成功说明这些结点之间是联通的，他们就相当于建立一个朋友圈；

重复选择未被访问的节点进行深度遍历，选择未被访问节点的次数就为朋友圈个数。



#define MAX_N 201

int g_n = 0;
int g_visitFlag[MAX_N] = {0};
int g_friendCycleNum = 0;


int g_stackInfo[MAX_N] = {0};
int g_stackNum = 0;

void InitProc()
{
    int i;

    g_n = 0;
    g_friendCycleNum = 0;

    for (i = 0; i < MAX_N; i++) {
        g_visitFlag[i] = 0;
    }

}

int IsVisitFinish(int *firstUnVisit)
{
    int i;

    for (i = 0; i < g_n; i++) {
        if (g_visitFlag[i] == 0) {
            *firstUnVisit = i;
            return 0;
        }
    }   

    return 1;
}


void InitDFSStack()
{
    int i;

    for (i = 0; i < g_stackNum; i++) {
        g_stackInfo[i] = 0;
    }

    g_stackNum = 0;
}



void DFS(int** M, int firstUnVisit)
{
    InitDFSStack();

    g_visitFlag[firstUnVisit] = 1;

    g_stackInfo[0] = firstUnVisit;
    g_stackNum++;

    while (g_stackNum > 0) {

        int stackTop = g_stackInfo[g_stackNum - 1];

        g_stackInfo[g_stackNum - 1] = 0;
        g_stackNum--;

        g_visitFlag[stackTop] = 1;

        int i;
        for (i = 0; i < g_n; i++) {
            if (g_visitFlag[i] == 0 && stackTop != i && M[stackTop][i] == 1) {
                    g_stackInfo[g_stackNum] = i;
                    g_stackNum++;
                    g_visitFlag[i] = 1;
            }
        }
    }
}


void AlgoProc(int** M)
{
    int firstUnVisit;
    while (!IsVisitFinish(&firstUnVisit)) {
        DFS(M, firstUnVisit);
        g_friendCycleNum++;
    }
}

void ParaSave(int MSize)
{
    g_n = MSize;
}

int GetResult()
{
    return g_friendCycleNum;  
}


int findCircleNum(int** M, int MSize, int* MColSize){

    InitProc();

    ParaSave(MSize);

    AlgoProc(M);

    return GetResult();
}