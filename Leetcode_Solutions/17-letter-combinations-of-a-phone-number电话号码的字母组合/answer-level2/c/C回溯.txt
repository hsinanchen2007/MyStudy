/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int g_index;
int GetCombineCount(char * digits)
{
    int digitLen = strlen(digits);
    int res = 1;

    for (int i = 0; i < digitLen; i++) {
        if (digits[i] == '7' || digits[i] == '9') {
            res *= 4;
        } else {
            res *= 3;
        }
    }

    return res;
}

char GetWord(char digit, int index)
{
    char result;
    
    if (digit >= '2' && digit <= '7') {
        result = ((digit - '2') * 3 + index) + 'a';
    } else if (digit == '8') {
        result = 't' + index;
    } else {
        result = 'w' + index;
    }

    return result;
}

void Dfs(int index, char *digits, int digitLen, char **res, char *oneResult) {
    int loop;
    char word;

    if (index == digitLen) {
        memcpy(res[g_index], oneResult, digitLen);
        g_index++;
        return;
    }

    if (digits[index] == '7' || digits[index] == '9') {
        loop = 4;
    } else {
        loop = 3;
    }
   
    for (int i = 0; i < loop; i++) {
        word = GetWord(digits[index], i);
        oneResult[index] = word;
        Dfs(index + 1, digits, digitLen, res, oneResult);
    }
}
char ** letterCombinations(char * digits, int* returnSize){
    char **res = NULL;
    int digitLen;
    int resCount;
    char oneResult[10];

    if (digits == NULL || strlen(digits) == 0) {
        *returnSize = 0;
        return NULL;
    } 
    digitLen = strlen(digits);
    resCount = GetCombineCount(digits);

    res = (char **)malloc(sizeof(char *) * resCount);
    for (int i = 0; i < resCount; i++) {
        res[i] = (char *)malloc(sizeof(char) * (digitLen + 1));
        res[i][digitLen] = '\0';
    }

    oneResult[digitLen] = '\0';
    g_index = 0;
    Dfs(0, digits, digitLen, res, oneResult);
    *returnSize = resCount;
    return res;
}