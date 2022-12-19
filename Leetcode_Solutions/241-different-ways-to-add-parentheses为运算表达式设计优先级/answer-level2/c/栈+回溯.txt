步骤：
1、字符串预处理，字符转成int型
2、把第一个数字入栈，后面每次处理2个数据(1个运算符+1个数字)
3、处理分2个分支：
   把2个数据入栈
   或者弹出3个数据，计算完再入栈1个数据
4、所有数据处理完，再从后向前计算栈数值

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int GetNums(char *input, int *map, int len)
{
    int i;
    int cnt = 0;
    int tmp;

    for (i = 0; i < len; i++) {
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*')) {
            map[cnt++] = -input[i];
            continue;
        }
        tmp = 0;
        while ((input[i] >= '0') && (input[i] <= '9')) {
            tmp = tmp * 10 + (input[i] - '0');
            i++;
        }
        map[cnt++] = tmp;
        i--;
    }
    return cnt;
}

int CalTotal(int n)
{
    int i;
    int ret = 1;

    for (i = 2; i <= n; i++) {
        ret *= i;
    }
    return ret;
}

int CalNum(int x, int cha, int y)
{
    if (cha == -'+') {
        return x+y;
    } else if (cha == -'-') {
        return x-y;
    } else {
        return x*y;
    }
}

int CalAnswer(int *stack1, int top)
{
    int i = top;
    int tmp;

    tmp = stack1[top];
    while (i > 1) {
        tmp = CalNum(stack1[i-2], stack1[i-1], tmp);
        i--;
        i--;
    }
    return tmp;
}

void GetDiffWays(int *map, int mapNum, int *stack1, int top, int wayCnt, int *ret, int *retCnt)
{
    int i;
    int tmp;
    int tmp1;
    int tmp2;

    if (wayCnt >= mapNum) {
        /*
        for (i = 0; i <= top; i++) {
            if (stack1[i] == -'+') {
                printf("+ ");
            } else if (stack1[i] == -'-') {
                printf("- ");
            } else if (stack1[i] == -'*') {
                printf("* ");
            } else {
                printf("%d ", stack1[i]);
            }
        }*/
        ret[*retCnt] = CalAnswer(stack1, top);
        //printf("= %d\n", ret[*retCnt]);
        (*retCnt)++;
        return;
    }
    //printf("add to stack %d %d %d\n", map[wayCnt], map[wayCnt+1], top);

    stack1[top+1] = map[wayCnt];
    stack1[top+2] = map[wayCnt+1];
    GetDiffWays(map, mapNum, stack1, top+2, wayCnt+2, ret, retCnt);
    
    if (top > 1) {
        //printf("pop stack %d %d %d\n", stack1[top-2], stack1[top-1], stack1[top]);
        tmp = stack1[top-2];
        tmp1 = stack1[top-1];
        tmp2 = stack1[top];
        stack1[top-2] = CalNum(stack1[top-2], stack1[top-1], stack1[top]);
        GetDiffWays(map, mapNum, stack1, top-2, wayCnt, ret, retCnt);
        stack1[top-2] = tmp;
        stack1[top-1] = tmp1;
        stack1[top] = tmp2;
    }

    return;
}

int* diffWaysToCompute(char * input, int* returnSize){
    if ((input == NULL) || (strlen(input) == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int len = strlen(input);
    int *map = malloc(sizeof(int) * len);
    int num = GetNums(input, map, len);
    int cnt = (num-1)/2;
    int *ret = malloc(sizeof(int) * CalTotal(cnt));
    int retCnt = 0;
    int i;
    int *stack1 = malloc(sizeof(int) * len);

    stack1[0] = map[0];
    GetDiffWays(map, num, stack1, 0, 1, ret, &retCnt);

    free(map);
    free(stack1);
    *returnSize = retCnt;
    return ret;
}
```
