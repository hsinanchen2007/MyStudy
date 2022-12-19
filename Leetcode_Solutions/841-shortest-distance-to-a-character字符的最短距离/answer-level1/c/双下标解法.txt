int *shortestToChar(char *S, char C, int *returnSize) {
    int *resultData = calloc(sizeof(int), strlen(S));
    int begin = 0;
    int end = 0;
    if (resultData == NULL) {
        return -1;
    }
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] == C) {
            resultData[i] = 0;
            continue;
        }
        while (1) {
            if (S[i - ++begin >= 0 ? i - begin : 0] == C) {
                resultData[i] = begin;
                begin = end = 0;
                break;
            }
            if (S[i + ++end < strlen(S) ? i + end : strlen(S) - 1] == C) {
                resultData[i] = end;
                begin = end = 0;
                break;
            }
        }

        begin = end = 0;
    }
    *returnSize = strlen(S);
    return resultData;
}