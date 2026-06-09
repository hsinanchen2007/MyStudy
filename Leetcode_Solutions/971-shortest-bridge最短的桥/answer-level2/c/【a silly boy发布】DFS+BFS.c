```
#define MAXSIZE 10000

#define SOURCESUM 2
#define DESINATIONSUM 1

void SubFuncDFS(int** A, int ASize, int* AColSize, int i, int j)
{
    if (A[i][j] != 1) {
        return;
    }
    A[i][j] = SOURCESUM;

    int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int tmpI, tmpJ;
    for (int k = 0; k < 4; k++) {
        tmpI = i + dir[k][0];
        tmpJ = j + dir[k][1];
        if ((tmpI >= 0) && (tmpI < ASize) && (tmpJ >= 0) && (tmpJ < *AColSize)) {
            if (A[tmpI][tmpJ] == 1) {
                SubFuncDFS(A, ASize, AColSize, tmpI, tmpJ);
            }
        }   
    }
}

typedef struct {
    int i;
    int j;
    int level;
    struct ListNode *next;
} ListNode;
ListNode *g_listNode;
int g_listNodeNum = 0;

void ListNodeInQueue(int i, int j, int level)
{
    ListNode *tmpListNode = g_listNode;
    if (g_listNodeNum == 0) {
        g_listNode = (ListNode *)malloc(sizeof(ListNode));
        g_listNode->i = i;
        g_listNode->j = j;
        g_listNode->level = level;
        g_listNode->next = 0;
        g_listNodeNum = 1;
    } else {
        while (tmpListNode->next != NULL) {
            tmpListNode = tmpListNode->next;
        }
        tmpListNode->next = (ListNode *)malloc(sizeof(ListNode));
        tmpListNode = tmpListNode->next;
        tmpListNode->i = i;
        tmpListNode->j = j;
        tmpListNode->level = level;
        tmpListNode->next = 0;
        g_listNodeNum++;
    }
}

bool ListNodeOutQueue(ListNode *sNode)
{
    ListNode *tmpListNode = g_listNode;
    ListNode *tmpagoListNode = g_listNode;
    if (g_listNodeNum == 0) {
        return false;
    } else {
        if (g_listNode->next == NULL) {
            sNode->i = g_listNode->i;
            sNode->j = g_listNode->j;
            sNode->level = g_listNode->level;  
            sNode->next = g_listNode->next; 
            free(g_listNode);
            g_listNodeNum = 0;
        } else {
            tmpagoListNode = tmpagoListNode->next;
            sNode->i = tmpListNode->i;
            sNode->j = tmpListNode->j;
            sNode->level = tmpListNode->level;  
            sNode->next = tmpListNode->next;
            free(tmpListNode);
            g_listNode = tmpagoListNode;
            g_listNodeNum--;
        }
    }
    return true;
}

void SubFuncBFSTarget(int** A, int ASize, int* AColSize, int target, int *distance, int **visited, int finalDistance)
{
    ListNode s;
    int i;
    bool isValid;
    isValid = ListNodeOutQueue(&s);

    if (isValid == true) {
        if ((s.level - 1) >= finalDistance) {
            return;
        }
        if (target == A[s.i][s.j]) {
            *distance = s.level - 1;
            return;
        } else {
            *distance = MAXSIZE;
        }
    }

    if (isValid == false) {
        return;
    }

    int dir[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    for (i = 0; i < 4; i++) {
        int tmpX = s.i + dir[i][0];
        int tmpY = s.j + dir[i][1];
        if ((tmpX >= 0) && (tmpX < ASize) && (tmpY >= 0) && (tmpY < *AColSize)) {
            if ((A[tmpX][tmpY] != SOURCESUM) && (visited[tmpX][tmpY] == 0)) {
                ListNodeInQueue(tmpX, tmpY, s.level + 1);
                visited[tmpX][tmpY] = 1;
            }
        }
    }
    SubFuncBFSTarget(A, ASize, AColSize, target, distance, visited, finalDistance);
}

void RebuildA(int** A, int ASize, int* AColSize)
{
    int i, j;
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < *AColSize; j++) {
            if (A[i][j] == 1) {
                SubFuncDFS(A, ASize, AColSize, i, j);
                return;
            }
        }
    }
}

void ResetVisited(int **visited, int ASize, const int* AColSize)
{
    int i;
    for (i = 0; i < ASize; i++) {
        memset(visited[i], 0, (*AColSize) * sizeof(int));
    }
}

void DelQueue()
{   
    if (g_listNodeNum != 0) {
        ListNode sNode;
        while (ListNodeOutQueue(&sNode));
    }
}

int shortestBridge(int** A, int ASize, int* AColSize)
{
    RebuildA(A, ASize, AColSize);

    const int level = 0;
    g_listNodeNum = 0;
    const int target = DESINATIONSUM;
    int distance = MAXSIZE;
    int tmpDistance = 0;
    int **visited = (int **)malloc(ASize * sizeof(int *));
    int i, j;
    for (i = 0; i < ASize; i++) {
        visited[i] = (int *)malloc((*AColSize) * sizeof(int));
        memset(visited[i], 0, (*AColSize) * sizeof(int));
    }
    int k;
    for (i = 0; i < ASize; i++) {
        for (j = 0; j < *AColSize; j++) {
            if (A[i][j] == SOURCESUM) {
                ListNodeInQueue(i, j, level);
                visited[i][j] = 1;
                SubFuncBFSTarget(A, ASize, AColSize, target, &tmpDistance, visited, distance);
                distance = distance > tmpDistance ? tmpDistance : distance;
                ResetVisited(visited, ASize, AColSize);
                DelQueue();
            }
        }
    }
    for (i = 0; i < ASize; i++) {
        free(visited[i]);
    }
    free(visited);
    return distance;
}
```
