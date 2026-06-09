思路：碰到符号就分别计算左右部分分别能得到的值，按符号组合所有左右部分的值到答案中，再接着找下一个符号；如果没有找到符号，则返回当前数字。

内存申请这块没处理好，2000个大小用例能过，但这不是最优


    int GetNum(char *input, int begin, int end)
    {
        int i;
        int num = 0;

        for (i = begin; i <= end; i++) {
            num = num * 10 + input[i] - '0';
        }

        return num;
    }

    int* CalNum(char *input, int begin, int end, int *num)
    {
        int i;
        int m, n;
        int *out = NULL;
        int *leftOut = NULL;
        int *rightOut = NULL;
        int leftNum = 0;
        int rightNum = 0;
        bool isNum = true;
        int res = 0;

        out = (int *)malloc(sizeof(int) * 2000);
        *num = 0;

        for (i = begin; i <= end; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                leftOut = CalNum(input, begin, i - 1, &leftNum);
                rightOut = CalNum(input, i + 1, end, &rightNum);

                for (m = 0; m < leftNum; m++) {
                    for (n = 0; n < rightNum; n++) {
                        switch (input[i]) {
                            case '+':
                                res = leftOut[m] + rightOut[n];
                                break;
                            case '-':
                                res = leftOut[m] - rightOut[n];
                                break;
                            case '*':
                                res = leftOut[m] * rightOut[n];
                                break;
                            default:
                                break;
                        }
                        out[*num] = res;
                        *num += 1;
                    }
                }
                free(leftOut);
                free(rightOut);
                leftOut = NULL;
                rightOut = NULL;
                isNum = false;
            }
        }

        if (isNum) {
            out[*num] = GetNum(input, begin, end);
            *num += 1;
        }
        return out;
    }


    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    int* diffWaysToCompute(char * input, int* returnSize){
        return CalNum(input, 0, strlen(input) - 1, returnSize);
    }