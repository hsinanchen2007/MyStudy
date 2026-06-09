### 解题思路
此处撰写解题思路

### 代码

```c


int calc(int left, int right, char op)
{
    if (op == '+')
        return left + right;
    else if (op == '-')
        return left - right;
    else if (op == '*')
        return left * right;
    return 0;
}

/* start:data的起始位置（从底往上）  result保存所有可能的结果   返回值是所有结果的数量 */
int GetResult(int start, int end, int *data, char *op, int *result)
{
    if (start == end) {
        result[0] = data[start];
        return 1;
    }
    if (end - start == 1) {
        result[0] = calc(data[start], data[end], op[start]);
        return 1;
    }

    int resultLeft[500] = {0};
    int resultRight[500] = {0};
    int left, right;
    int ret = 0;
    for (int i = start; i <= end - 1; i++) {
        memset(resultLeft, 0x0, sizeof(int) * 500); // 清空上次递归得到的结果
        memset(resultRight, 0x0, sizeof(int) * 500);
        left = GetResult(start, i, data, op, resultLeft); // 递归左边
        right = GetResult(i + 1, end, data, op, resultRight); // 递归右边
        for (int k = 0; k < left; k++) { // 把左边和右边递归的结果组合起来，并放到result中
            for (int j = 0; j < right; j++) {
                result[ret++] = calc(resultLeft[k], resultRight[j], op[i]);
            }
        }
    }
    return ret;
}

int* diffWaysToCompute(char * input, int* returnSize){
    int data[100] = {0};
    char op[50] = {0};
    int number = 0;
    int i = 0;
    int *result = NULL;
    int opSize = 0;
    int dataSize = 0;

    while(input[i] != '\0') {
        if (isdigit(input[i])) {
            number = number * 10 + (int)(input[i] - '0');
        } else {
            data[dataSize] = number;
            dataSize++;
            op[opSize] = input[i];
            opSize++;
            number = 0;
        }
        i++;
    }
    data[dataSize] = number;
    dataSize++;

    result = (int *)malloc(sizeof(int) * 1500);
    memset(result, 0x0, sizeof(int) * 1500);

    if (dataSize == 1 && opSize == 0) {
        *returnSize = 1;
        result[0] = data[0];
        return result;
    }
    *returnSize = GetResult(0, dataSize - 1, data, op, result);
    return result;
}
```