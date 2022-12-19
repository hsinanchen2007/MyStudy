#define TEST_SUCC 0
#define TEST_FAIL 1

typedef struct {
    int *position;
    bool *jUsed;
    bool *leftUsed;
    bool *rightUsed;
}MapInfo;

MapInfo g_mapInfo = {0};

int InitMapInfo(int n)
{
    g_mapInfo.position = (int *)malloc(sizeof(int) * n);
    if (g_mapInfo.position == NULL) {
        UnInitMapInfo();
        return TEST_FAIL;
    }
    g_mapInfo.jUsed = (bool *)malloc(sizeof(bool) * n);
    if (g_mapInfo.jUsed == NULL) {
        UnInitMapInfo();
        return TEST_FAIL;
    }
    g_mapInfo.leftUsed = (bool *)malloc(sizeof(bool) * n *2);
    if (g_mapInfo.leftUsed == NULL) {
        UnInitMapInfo();
        return TEST_FAIL;
    }
    g_mapInfo.rightUsed = (bool *)malloc(sizeof(bool) * n *2);
    if (g_mapInfo.rightUsed == NULL) {
        UnInitMapInfo();
        return TEST_FAIL;
    }
    memset(g_mapInfo.position, 0, sizeof(int) * n);
    memset(g_mapInfo.jUsed, 0, sizeof(bool) * n);
    memset(g_mapInfo.leftUsed, 0, sizeof(bool) * n *2);
    memset(g_mapInfo.rightUsed, 0, sizeof(bool) * n *2);
    return TEST_SUCC;
    
}
void UnInitMapInfo(void)
{
    if (g_mapInfo.position) {
        free(g_mapInfo.position);
        g_mapInfo.position = NULL;
    }
    
    if (g_mapInfo.jUsed) {
        free(g_mapInfo.jUsed);
        g_mapInfo.jUsed = NULL;
    }
    if (g_mapInfo.leftUsed) {
        free(g_mapInfo.leftUsed);
        g_mapInfo.leftUsed = NULL;
    }
    if (g_mapInfo.rightUsed) {
        free(g_mapInfo.rightUsed);
        g_mapInfo.rightUsed = NULL;
    }
}


int calcQn(int n, MapInfo *mapInfo, int i)
{
    int j;
    int sum = 0;    
    
    for (j = 0; j < n; j++) {
        if ((mapInfo->jUsed[j] != false) || 
            (mapInfo->leftUsed[i + j] != false) ||
            (mapInfo->rightUsed[i - j + n -1] != false)) {
            continue;
        }
        if (i == n-1) {
            return 1;
        } else {
            mapInfo->position[i] = j;
            mapInfo->jUsed[j] = true;
            mapInfo->leftUsed[i + j] = true;
            mapInfo->rightUsed[i - j + n - 1] = true;
        
            sum += calcQn(n, mapInfo, i + 1);
            mapInfo->jUsed[j] = false;
            mapInfo->leftUsed[i + j] = false;
            mapInfo->rightUsed[i - j + n - 1] = false;
        }
    }
    return sum;
}

int totalNQueens(int n) {
    int j;
    int sum = 0;
    
    if (n == 0) {
        return 0;
    }
    
    if (TEST_SUCC != InitMapInfo(n)) {
        return 0;
    }
    
    sum = calcQn(n, &g_mapInfo, 0);
        
    UnInitMapInfo();
    return sum;
}

