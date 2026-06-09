/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void getRes(int left, int right, char *cur, int curLen, char **res, int n, int *resNum) {
    if (left == 0) {
        res[*resNum] = (char*)malloc(sizeof(char) * (2 * n + 1));
        memcpy(res[*resNum], cur, curLen);
        while (curLen != 2 * n) {
            res[*resNum][curLen] = ')';
            curLen++;
        }
        res[*resNum][curLen] = '\0';
        (*resNum)++;
        return;
    }
    if (left == right) {
        cur[curLen] = '(';
        curLen++;
        getRes(left-1, right, cur, curLen, res, n, resNum);
        return;
    }
    if (left < right) {
        cur[curLen] = '(';
        getRes(left-1, right, cur, curLen + 1, res, n, resNum);
        cur[curLen] = ')';
        getRes(left, right - 1, cur, curLen + 1, res, n, resNum);
        return;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    if (n ==0) {
        *returnSize = 0;
        return NULL;
    }
    char **res = (char**)malloc(sizeof(char *) * 0xffff);
    *returnSize = 0;
    char *cur = (char *)malloc(sizeof(char) * (2 * n));
    getRes(n, n, cur, 0, res, n, returnSize);
    return res;
}