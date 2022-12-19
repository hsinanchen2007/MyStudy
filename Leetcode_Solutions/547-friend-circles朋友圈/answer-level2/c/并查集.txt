// 并查集的解法，主要实现三个函数功能
// init
// find
// joint

typedef struct {
    int data;
    int rank;
    int parent;
}UfsNode;

void InitUfs(UfsNode node[], int MSize)
{
    for (int i = 0; i < MSize; i++) {
        node[i].data = i;
        node[i].rank = 0;
        node[i].parent = i;
    }

    return;
}

int FindParent(UfsNode node[], int i)
{
    while (node[i].parent != i) {
       i = FindParent(node, node[i].parent);
    }

    return i;
}

void Joint(UfsNode node[], int i, int j, int *numOfFriendCircle)
{
    int iParent = FindParent(node, i);
    int jParent = FindParent(node, j);
    if (iParent == jParent) {
        return;
    }

    (*numOfFriendCircle)--;
    if (node[iParent].rank > node[jParent].rank) {
        node[jParent].parent = iParent;
    } else if (node[iParent].rank > node[jParent].rank) {
        node[iParent].parent = jParent;
    } else {
        node[iParent].parent = jParent;
        node[jParent].rank++;
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int numOfFriendCircle = MSize;
    // printf("%u", MSize);
    // printf("\r\n%u", *MColSize);
    UfsNode node[MSize];
    InitUfs(node, MSize);
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i][j] == 1) {
                Joint(node, i, j, &numOfFriendCircle);
            }
        }
    }    
    // return 朋友圈的个数 
    return numOfFriendCircle;
}