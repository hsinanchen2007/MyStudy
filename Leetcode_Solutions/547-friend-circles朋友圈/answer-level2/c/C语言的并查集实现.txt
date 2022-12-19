int set[201];

int findFirstFriend(int i)
{
    if (set[i] == 0x5a5a5a5a) {
        return i;
    } else {
        return findFirstFriend(set[i]);
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int i, j, a, b;
    int ret = 0;
    
    if (MSize == 0) {
        return 0;
    }
    
    for (i = 0; i < MSize; i++) {
        set[i] = 0x5a5a5a5a;
    }
    
    for (i = 0; i < MSize; i++) {
        for (j = i+1; j < MSize; j++) {
            if (M[i][j] == 1) {
                a = findFirstFriend(i);
                b = findFirstFriend(j);
                
                if (a != b) {
                    set[b] = a;
                }
                
            }
        }
    }
    
    for (i = 0; i < MSize; i++) {
        if (set[i] == 0x5a5a5a5a) {
            ret++;
        }
    }
    return ret;
}

