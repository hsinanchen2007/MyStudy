
int g_size = 0;
bool cmp (const void* a, const void* b) {
    return *(int*)a > *(int*)b;
}

void DFS (int** land, int row, int clo, int cur_row, int cur_clo) {
    if (cur_row < 0 || cur_row > row - 1 || cur_clo < 0 || cur_clo > clo - 1 || land[cur_row][cur_clo] != 0) {
        return;
    }

    land[cur_row][cur_clo] = 1;
    g_size++;

    DFS(land, row, clo, cur_row - 1, cur_clo);
    DFS(land, row, clo, cur_row + 1, cur_clo);
    DFS(land, row, clo, cur_row, cur_clo - 1);
    DFS(land, row, clo, cur_row, cur_clo + 1);
    DFS(land, row, clo, cur_row - 1, cur_clo - 1);
    DFS(land, row, clo, cur_row + 1, cur_clo - 1);
    DFS(land, row, clo, cur_row - 1, cur_clo + 1);
    DFS(land, row, clo, cur_row + 1, cur_clo + 1);
}

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    if (landSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int clo = landColSize[0];
    int i, j;
    int waterNum = 0;
    int *rst = (int*)malloc(sizeof(int) * 500000);
    memset(rst, 1000000, sizeof(int) * 500000);

    for (i = 0; i < landSize; i++) {
        for (j = 0; j < clo; j++) {
            if (land[i][j] == 0) {
                DFS(land, landSize, clo, i, j);
                
                //printf("%d ", g_size);
                rst[waterNum] = g_size;

                waterNum++;
                g_size = 0;
            }
        }
    }
    qsort(rst, 500, sizeof(int), cmp);

    *returnSize = waterNum;
    return rst;
}