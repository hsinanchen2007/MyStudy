
void UpdateMap(int **M, int src, int des, int size)
{
    M[src][des] = 1;
    M[des][src] = 1;
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (M[i][j]) {
                    continue;
                }
                if (M[i][k] && M[k][j]) {
                    M[i][j] = 1;
                }
            }
        }
    }
}

int findCircleNum(int **M, int MSize, int *MColSize)
{
    if (MSize == 0 || M == NULL) {
        *MColSize = 0;
        return 0;
    }
    UpdateMap(M, 0, 0, MSize);
    int zeroNum = 1;
    for (int i = 0; i < MSize; i++) {
        for (int j = i; j < MSize; j++) {
            if (M[i][j] == 0) {
                zeroNum++;
                UpdateMap(M, i, j, MSize);
            }
        }
    }
    return zeroNum;
}
