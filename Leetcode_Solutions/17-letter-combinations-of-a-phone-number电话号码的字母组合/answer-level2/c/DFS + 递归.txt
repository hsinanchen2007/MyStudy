#define ROW_SIZE 1000
#define COLUMN_SIZE 16
char *g_cached = NULL;
int leftNum; // 左括号的个数
int rightNum;
int g_RowIdx = 0;
char *numMapToStr[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void step(int stepCnt, char * digits, int digitsSize, char **resutArr)
{
    if (stepCnt == digitsSize) {
        resutArr[g_RowIdx] = (char *)malloc(sizeof(char) * COLUMN_SIZE);
        memcpy(resutArr[g_RowIdx], g_cached, COLUMN_SIZE);
/* debug
        int j = 0;
        for (j = 0; j < 6; j++)
        {
            printf("%c",resutArr[g_RowIdx][j]);
        }
        printf("\r\n");
*/
        g_RowIdx++;
        return;
    }

    char stepChar = digits[stepCnt];
    unsigned char charToNum = stepChar - '0';
    char *currentStepStr = numMapToStr[charToNum - 2];
    int currentStepStrLen = strlen(currentStepStr);
    int i;
    for (i = 0; i < currentStepStrLen; i++) {
        g_cached[stepCnt] = currentStepStr[i];
        step(stepCnt + 1, digits, digitsSize, resutArr);
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    if (digits == NULL || returnSize == NULL) {
        return NULL;
    }

    if (strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    }

    char **result = (char **)malloc(sizeof(char *) * ROW_SIZE);
    if (result == NULL) {
        return NULL;
    }

    g_cached = (char *)malloc(sizeof(char) * COLUMN_SIZE);
    memset(g_cached, 0, sizeof(char) * COLUMN_SIZE);

    g_RowIdx = 0;

    int digitSize = strlen(digits);
    step(0, digits, digitSize, result);
    
    *returnSize = g_RowIdx;

    return result;
}
