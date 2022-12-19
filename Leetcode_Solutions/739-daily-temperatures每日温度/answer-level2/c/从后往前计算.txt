
    int* dailyTemperatures(int* T, int TSize, int* returnSize){
        int *res = (int *)malloc(sizeof(int) * TSize);
        if (res == NULL) {
            return NULL;        
        }

        for (int i = 0; i < TSize; i++) {
            res[i] = 0;
        }
        
        for (int i = TSize - 2; i >= 0; i--) {
            for (int j = i + 1; j < TSize; j += res[j]) {
                if (T[j] > T[i]) {
                    res[i] = j - i;
                    break;
                } else if (res[j] == 0) {
                    res[i] = 0;
                    break;
                }
            }        
        }
        
        *returnSize = TSize;
        return res;
    }
