暴力解法
1. 通过两个滑窗遍历组合，确定斐波那契式的序列的首两位整数
2. 在确定首两位整数后，按照斐波那契式计算后续序列，通过迭代，验证字符是否满足
3. 特别关注下滑窗确定首两位数字时，0是否是滑窗的首位，0只能自身作为单个数字
4. 减少遍历，关注滑窗的大小及滑窗内数字不能超过INT_MAX

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NUMBER 2147483647
#define MAX_NUMBER_STR "2147483647"
#define MAX_NUMBER_LEN 10
#define MAX_STR_LEN 12

/* 确定了前两位数字，可以直接验证后续字符是否满足斐波那契式序列 */
bool iterCheckFibonacci(char *S, int firstStart, int firstWind, int secondStart, int secondWind, int *result, int *returnSize)
{
    int strLen = strlen(S);
    if (((strLen - (secondStart + secondWind)) < firstWind) || ((strLen - (secondStart + secondWind)) < secondWind)) {
        *returnSize = 0;
        return false;
    }
    char firstStr[MAX_STR_LEN] = {0};
    strncpy(firstStr, S + firstStart, firstWind);
    int firstNum = atoi(firstStr);
    result[(*returnSize)++] = firstNum;

    char secondStr[MAX_STR_LEN] = {0};
    strncpy(secondStr, S + secondStart, secondWind);    
    int secondNum = atoi(secondStr);          
    if ((MAX_NUMBER - secondNum) < firstNum) {
        *returnSize = 0;
        return false;
    }

    char nextExpectStr[MAX_STR_LEN] = {0};
    sprintf(nextExpectStr, "%d", (firstNum + secondNum));      
    if ((strLen - (secondStart + secondWind)) < strlen(nextExpectStr)) {
        *returnSize = 0;
        return false;
    }

    if (strncmp((S + secondStart + secondWind), nextExpectStr, strlen(nextExpectStr)) != 0) {
        *returnSize = 0;
        return false;
    }
    
    if ((secondStart + secondWind + strlen(nextExpectStr)) == strLen) {
        result[(*returnSize)++] = secondNum;
        result[(*returnSize)++] =  (firstNum + secondNum);
        return true;
    }
    
    return iterCheckFibonacci(S, secondStart, secondWind, secondStart + secondWind, strlen(nextExpectStr), result, returnSize);
}

int* splitIntoFibonacci(char * S, int* returnSize)
{
    int strLen = strlen(S);
    if (strLen <= 2) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int *)malloc(sizeof(int) * strLen);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    memset(result, 0, sizeof(int) * strLen);
    *returnSize = 0;
    for (int winWidth = 1; (winWidth < strLen) && (winWidth <= MAX_NUMBER_LEN); winWidth++) {
        /* 控制第一位数滑窗大小 */
        if ((winWidth == MAX_NUMBER_LEN) && (strncmp(S, MAX_NUMBER_STR, MAX_NUMBER_LEN) > 0)) {
            *returnSize = 0;
            return result;
        }
        
        /* 首字符为0，只有一种拆分方式 */
        if ((S[0] == '0') && (winWidth != 1)) {
            *returnSize = 0;            
            return result;
        }
        
        for (int innerWinWidth = 1; (winWidth + innerWinWidth < strLen) && (innerWinWidth <= MAX_NUMBER_LEN); innerWinWidth++) {
            /* 控制第二位数滑窗大小 */
            if ((innerWinWidth == MAX_NUMBER_LEN) && (strncmp(S + winWidth, MAX_NUMBER_STR, MAX_NUMBER_LEN) > 0)) {
                break;
            }
            
            /* 第二位数首字符为0，若没有有效拆分序列方案，则直接跳过，继续扩展第一个数字滑窗 */
            if (S[winWidth] == '0') {
                if (iterCheckFibonacci(S, 0, winWidth, winWidth, innerWinWidth, result, returnSize) == true) {                    
                    return result;
                }
                
                break;
            }
            
            if (iterCheckFibonacci(S, 0, winWidth, winWidth, innerWinWidth, result, returnSize) == true) {                    
                return result;
            }            
            continue;
        }
    }

    *returnSize = 0;
    return result;
}


```
