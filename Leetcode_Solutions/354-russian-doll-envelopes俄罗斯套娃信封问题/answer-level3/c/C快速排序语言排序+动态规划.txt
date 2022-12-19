int compare(const void *a, const void *b)
{
    int *ap = *(int **)a;
    int *bp = *(int **)b;

    if (ap[0] == bp[0]) {
        return bp[1] - ap[1];
    } else {
        return ap[0] - bp[0];
    }
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    if (envelopes == NULL || envelopesSize == 0 || *envelopesColSize == 0) {
        return 0;
    }
    int maxVal;
    int maxSeq;

    // dp[i]表示以i结尾的最大上升子串的长度
    // dp[i] = MAX(dp[j]) + 1; j < i且envelop[j][0] < envelop[i][0]
    int *dp = (int *)malloc(sizeof(int) * envelopesSize); 
    dp[0] = 1;

    qsort(envelopes, envelopesSize, sizeof(envelopes[0]), compare);

    maxSeq = dp[0];
    for (int i = 1; i < envelopesSize; i++) {
        maxVal = 0;
        for (int j = 0; j < i; j++) {
            if (envelopes[j][1] < envelopes[i][1]) {
                if (maxVal < dp[j]) {
                    maxVal = dp[j];
                }
            }
        }
        dp[i] = maxVal + 1;
        if (maxSeq < dp[i]) {
            maxSeq = dp[i];
        }
    }

    return maxSeq;
}
