### 解题思路
回溯法

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void generate(int left, int right, char **result, int *returnSize, char *item, int itemIndex, int n)
{
    if (left == 0 && right == 0)
    {
        result[*returnSize] = (char *)malloc(sizeof (char) * (2 * n + 1));
        item [itemIndex] = '\0';
        strcpy(result[(*returnSize) ++], item);

        return;
    }

    item[(itemIndex)] = '(';

    if (left > 0)
    {
        //item[(itemIndex) ++] = '(';
        //printf("%d, %d\n", left, right);
        generate(left - 1, right, result, returnSize, item, itemIndex + 1, n);
    }

    if (right > left)
    {
        item[(itemIndex) ++] = ')';
        //printf("%d, %d\n", left, right);
        generate(left, right - 1, result, returnSize, item, itemIndex, n);
    }
}

char ** generateParenthesis(int n, int* returnSize){

    if (0 == n)
    {
        return NULL;
    }

    char **res;
    res = (char **)malloc(sizeof(char *) * 2000);
    char *item;
    item = (char *)malloc(sizeof(char) * (100));
    int itemIndex = 0;
    *returnSize = 0;

    generate(n, n, res, returnSize, item, itemIndex, n);

    return res;
}
```