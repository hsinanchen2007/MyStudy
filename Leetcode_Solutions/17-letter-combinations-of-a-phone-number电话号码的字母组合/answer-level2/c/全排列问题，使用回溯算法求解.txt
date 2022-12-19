### 解题思路
全排列问题，使用回溯算法求解

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXLEN 0xffff

char num2[] = {'a', 'b', 'c'};
char num3[] = {'d', 'e', 'f'};
char num4[] = {'g', 'h', 'i'};
char num5[] = {'j', 'k', 'l'};
char num6[] = {'m', 'n', 'o'};
char num7[] = {'p', 'q', 'r', 's'};
char num8[] = {'t', 'u', 'v'};
char num9[] = {'w', 'x', 'y', 'z'};
char * getNums(int index, int* numSize) {
    char *nums = NULL;
    switch (index) {
        case 2:
            (*numSize) = sizeof(num2)/sizeof(char);
            nums = num2;
            break;
        case 3:
            (*numSize) = sizeof(num3)/sizeof(char);
            nums = num3;
            break;
        case 4:
            (*numSize) = sizeof(num4)/sizeof(char);
            nums = num4;
            break;
        case 5:
            (*numSize) = sizeof(num5)/sizeof(char);
            nums = num5;
            break;
        case 6:
            (*numSize) = sizeof(num6)/sizeof(char);
            nums = num6;
            break;
        case 7:
            (*numSize) = sizeof(num7)/sizeof(char);
            nums = num7;
            break;
        case 8:
            (*numSize) = sizeof(num8)/sizeof(char);
            nums = num8;
            break;
        case 9:
            (*numSize) = sizeof(num9)/sizeof(char);
            nums = num9;
            break;
        default:
            (*numSize) = 0;
            break;
    }

    return nums;
}
void combination(char * digits, int pos, char *buf, char **res, int* returnSize) {

    if (pos == strlen(digits)) {
        buf[pos] = '\0';
        res[(*returnSize)] = (char*)malloc(sizeof(char)*(strlen(digits)+1));
        memcpy(res[(*returnSize)], buf, sizeof(char)*(strlen(digits)+1));
        (*returnSize)++;
        return;
    }
    int currentNum = digits[pos] - '0'; 
    //printf("currentNum = %d\n", currentNum);
    int numSize = 0;
    char *nums = getNums(currentNum, &numSize);
    //printf("size = %d\n", numSize);
    for (int index = 0; index < numSize; index++) {
        //printf("index=%d, buf[%d]=%c\n", index, pos, nums[index]);
        buf[pos] = nums[index];
        combination(digits, pos+1, buf, res, returnSize);
    }
    return;
}

char ** letterCombinations(char * digits, int* returnSize){
    (*returnSize) = 0;
    if (digits == NULL || strlen(digits) == 0) {
        return NULL;
    }
    int len = strlen(digits);
    char *buf = (char*)malloc(sizeof(char)*(len+1));
    char **res = (char**)malloc(sizeof(char*)*MAXLEN);

    combination(digits, 0, buf, res, returnSize);
    return res;
}
```