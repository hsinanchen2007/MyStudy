### 解题思路
此处撰写解题思路
这道题其实就是深度优先搜索类型，用递归实现。

递归函数：传入一个字符串和要处理的位数(index)
递归函数就是对字符串中index位的字符进行：保持不变或者变化，两种选择。(如果是数字，只能保持不变)
如果保持不变，就继续递归，参数为：字符串(旧)，index + 1等
如果变化，就将输入的字符串copy一份，修改字符串的index位的字符，从而得到新的字符串。并将字符串的地址保存到要返回的数组中，还要保存字符串的个数。
然后继续递归，参数为：字符串（新），index + 1等

### 代码

```c
#define COUNT 10000

static char change(char c, char mask) {
    if ((c >= 'a') && (c <= 'z')) {
        return c - mask;
    } else {
        return c + mask;
    }
}
static void newChar(char* input, int inputSize, int inIndex, char** res, int *resNewIndex, char mask) {
    char* newRow = NULL;

    if (input[inIndex] == '\0') {
        return;
    }
    if ((input[inIndex] < '0') || (input[inIndex] > '9')) {
        newChar(input, inputSize, inIndex + 1, res, resNewIndex, mask);
        newRow = (char*)malloc(sizeof(char) * inputSize + 1);
        strncpy(newRow, input, inputSize);
        newRow[inputSize] = '\0';
        newRow[inIndex] = change(input[inIndex], mask);
        res[*resNewIndex] = newRow;
        (*resNewIndex)++;

        newChar(newRow, inputSize, inIndex + 1, res, resNewIndex, mask);
    } else {
        newChar(input, inputSize, inIndex + 1, res, resNewIndex, mask);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * S, int* returnSize){
    int i, j;
    size_t len = strlen(S);
    size_t row = sizeof(char*) * COUNT;
    char** res = NULL;
    char* resCow = NULL;
    int resNewIndex = 0;
    char mask = 'a' - 'A';

    res = (char**)malloc(row);
    if (res == NULL) {
        printf("malloc failed\n");
        return NULL;
    }
    
    memset(res, 0, row);
    
    if (strlen(S) == 0) {
        res[0] = (char*)malloc(sizeof(char));
        memset(res[0], 0, sizeof(char));
        *returnSize = 1;
        return res;
    }

    resCow = (char*)malloc(len + 1);
    strncpy(resCow, S, len);
    resCow[len] = '\0';
    res[0] = resCow;
    resNewIndex++;

    printf("%d\n", mask);   
    newChar(S, len, 0, res, &resNewIndex, mask); 

    *returnSize = resNewIndex;

    return res;
}
```