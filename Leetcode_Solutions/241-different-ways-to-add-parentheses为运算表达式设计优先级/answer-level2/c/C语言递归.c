/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isCalcSymbol(char aChar) {
    if (aChar == '+' || aChar == '-' || aChar == '*') {
        return true;
    } else {
        return false;
    }
}

int Calculator(int a, int b, char symbol) 
{
    switch (symbol) {
        case '+':
            a = a + b;
            break;
        case '-':
            a = a - b;
            break;
        case '*':
            a = a * b;
            break;
        default:
            break;
    }
    return a;
}

int* diffWaysToCompute(char * input, int* returnSize){
    int allNumFlag = 1;
    /* 遍历输入以符号为中心对半分开数组分治 */
    int idx = 0;
    int rtnSize = 0;
    int *resultArray = (int*)malloc(sizeof(int));
    int resultCnt = 0;
    while (idx < strlen(input)) {
        /* 寻找符号 */
        if (isCalcSymbol(input[idx])) {
            allNumFlag = 0;
            /* 分左右数组 */
            char *leftArray = (char*)calloc(idx + 1, sizeof(char));
            memcpy(leftArray, &input[0], idx);
            leftArray[idx] = '\0';
            char *rightArray = (char*)calloc(strlen(input) - idx, sizeof(char));
            memcpy(rightArray, &input[idx + 1], strlen(input) - idx - 1);
            rightArray[strlen(input) - idx - 1] = '\0';
            int leftReturnSize = 0;
            int rightReturnSize = 0;
            /* 递归 */
            int *leftNums = diffWaysToCompute(leftArray, &leftReturnSize);
            int *rightNums = diffWaysToCompute(rightArray, &rightReturnSize);

            /* 同层可能性累加 */
            rtnSize += leftReturnSize * rightReturnSize;
            int *result = (int*)realloc(resultArray, rtnSize * sizeof(int));
            if (result == NULL) {
                return NULL;
            }
            resultArray = result;
            /* 左右返回数组组合后的所有可能性 */
            for (int i = 0; i < leftReturnSize; i++) {
                for (int j = 0; j < rightReturnSize; j++) {
                    resultArray[resultCnt++] =  Calculator(leftNums[i], rightNums[j], input[idx]);
                }
            }
        }
        idx++;
    }
    /* base case */
    if (allNumFlag == 1) {
        resultArray[0] = atoi(input);
        *returnSize = 1;
        return resultArray;
    }
    *returnSize = rtnSize;
    return resultArray;
}