```
int max(int a, int b) {
    if(a > b) {
        b = a;
    }
    return b;
}

int removeBoxesSub(int* boxes,int i, int j, int k, int ***dp) {
    if (i > j) {
        return 0;
    }
    if(dp[i][j][k] > 0) {
        return dp[i][j][k];
    }

    int ans = (k + 1) * (k + 1) + removeBoxesSub(boxes, i + 1, j, 0, dp);
    for (int m = i + 1; m <= j; m++) {
        if (boxes[m] == boxes[i]) {
            ans = max(ans, removeBoxesSub(boxes, i + 1, m - 1, 0, dp) + removeBoxesSub(boxes, m, j, k + 1, dp));
        }
    }
    dp[i][j][k] = ans;
    return ans;
}

int removeBoxes(int* boxes, int boxesSize) {
    int ***dp = (int ***)malloc(boxesSize * sizeof(int **));
    for(int i = 0; i < boxesSize; i++) {
        dp[i] = (int **)malloc(boxesSize * sizeof(int *));
        for(int j = 0; j < boxesSize; j++) {
            dp[i][j] = (int*)malloc(boxesSize * sizeof(int));
        }
    }
    for (int i = 0; i< boxesSize; i++) {
        for (int j = 0; j < boxesSize; j++) {
            for (int k = 0; k < boxesSize; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    int ans = removeBoxesSub(boxes, 0, boxesSize - 1, 0, dp);
    for (int i = 0; i< boxesSize; i++) {
        for (int j = 0; j < boxesSize; j++) {
            free(dp[i][j]);
        }
    }
    for (int i = 0; i< boxesSize; i++) {
        free(dp[i]);
    }
    free(dp);
    return ans;
}
```