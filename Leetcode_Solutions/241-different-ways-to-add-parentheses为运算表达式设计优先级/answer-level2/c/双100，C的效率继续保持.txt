### 解题思路
开局也不知道有多少数字，最终来看样本最多就不到10个数字，双100，C的效率继续保持

![image.png](https://pic.leetcode-cn.com/98ee4efca08cc9e9d6ffcfb45446ed85256bf3480e9eb162d6ec462eef088cfc-image.png)
动态规划想出来很容易，写出来有点绕

### 代码

```c
// dp[i][j]的结果存储
typedef struct 
{
    int *calRst;
    int rstCnt;
} DpRstInfo;


//#define __DEBUG
#ifdef __DEBUG
#define DEBUG(format, ...) printf (format, ##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#endif

#define MAX_COUNT 10

//回溯会把所有的点的结果都保存起来
DpRstInfo g_dpResult[MAX_COUNT][MAX_COUNT];

void printNumberAndOperator(int *number, int cnt, char *opera, int c_cnt)
{
    int i;
    for (i = 0; i < cnt; i++) {
        DEBUG("number:%d\n", number[i]);
    }
    for (i = 0; i < c_cnt; i++) {
        DEBUG("number:%c\n", opera[i]);
    }
}

int algcalc(int a, int b, char op) {
    switch (op)
    {
    case '*':
        return a * b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    default:
        return -1;
    }
}

void calcDpPoint(int x, int y, char *operator, int operaCnt)
{
    int i, j, k;
    int count = 0;
    for (i = 0; i < y; i++) {
        count += (g_dpResult[x][x+i].rstCnt) * (g_dpResult[x+i+1][x+y].rstCnt);
    }
    g_dpResult[x][x+y].rstCnt = count;

    int * value = (int *)malloc(count * sizeof(int));
    count = 0;
    for (i = 0; i < y; i++) {
        for (j = 0; j < g_dpResult[x][x+i].rstCnt; j++) {
            for (k = 0; k < g_dpResult[x+i+1][x+y].rstCnt; k++) {
                value[count] = algcalc(g_dpResult[x][x+i].calRst[j], g_dpResult[x+i+1][x+y].calRst[k], operator[x+i]);
                count++;
            }
        }
    }
    g_dpResult[x][x+y].calRst = value;
}

void dynamicCalc(int * numbers, int numberCnt, char * operators,int operaCnt)
{
    if (numberCnt > MAX_COUNT) {
        printf("number cnt > %d.\n", MAX_COUNT);
    }

    int i, j;
    int *value;

    for (i = 0; i < numberCnt; i++) {
        value = (int *)malloc(sizeof(int));
        *value = numbers[i];
        g_dpResult[i][i].calRst = value;
        g_dpResult[i][i].rstCnt = 1;
    }
    
    for (i = 1; i < numberCnt; i++) {
        for (j = 0; j < numberCnt; j++) {
            if ((i + j) < numberCnt) {
                // calc dp[j][j+i]
                DEBUG("calc :[%d,%d]", j, j + i);
                calcDpPoint(j, i, operators, operaCnt);
            }
        }
    }

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char * input, int* returnSize){
    /* 提取数字和符号 */
    if(strlen(input) == 0) {
        *returnSize = 0;
        return NULL;
    }

    int maxCnt = strlen(input);

    int *numbers = (int *)malloc(maxCnt * sizeof(int));
    char *operators = (char *)malloc(maxCnt * sizeof(char));
    int numberCnt = 0;
    int operaCnt = 0;

    int i, j;
    int num = 0;
    for (i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            num = (10 * num + (input[i] - '0'));
        } else {
            operators[operaCnt] = input[i];
            operaCnt++;

            numbers[numberCnt] = num;
            numberCnt++;
            num = 0;
        }
    }

    numbers[numberCnt] = num;
    numberCnt++;

    if (numberCnt == 1) {
        *returnSize = 1;
        return numbers;
        free(operators);
    }

    printNumberAndOperator(numbers, numberCnt, operators, operaCnt);

    memset(g_dpResult, 0, sizeof(g_dpResult));

    dynamicCalc(numbers, numberCnt, operators, operaCnt);

    *returnSize = g_dpResult[0][numberCnt-1].rstCnt;

    for (i = 0 ; i < numberCnt; i++) {
        for (j = 0; j < numberCnt; j++) {
            if ((i == 0) && (j == numberCnt - 1)) {
                continue;
            }
            if (g_dpResult[i][j].calRst != NULL) {
                free(g_dpResult[i][j].calRst);

            }
            memset(&g_dpResult[i][j], 0, sizeof(DpRstInfo));
        }
    }
    free(numbers);
    free(operators);
    return g_dpResult[0][numberCnt-1].calRst;
}
```