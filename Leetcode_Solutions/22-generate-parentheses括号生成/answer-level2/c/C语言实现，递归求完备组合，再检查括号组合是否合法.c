思路：1、将括号先转化为数字，1对应"("，-1对应")"，生成组合后再转化为括号；
2、递归求括号的完备组合；
3、检查括号组合是否合法，合法条件：任意前n项和不小于0，且，总和为0；

![括号生成.PNG](https://pic.leetcode-cn.com/dff5df2c906a29764a32529da32f7026fcd5ef497c521df05767ead1f70ee64a-%E6%8B%AC%E5%8F%B7%E7%94%9F%E6%88%90.PNG)

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int mutiply_n(int n)
{
    int f = 1;
    while (n) {
        f *= n;
        n--;
    }
    
    return f;
}

int check(char *p, int n)
{
    int f = 0;
    for(int i = 0; i < n; i++) {
        f += p[i];
        if (f < 0) {
            return -1;
        }
    }
    if (f != 0) {
        return -1;
    }
    return 1;
}

int func(char *p, int i, int num, int* retSize, char **ret)
{
    if (i == num) {
        p[i] = 0;
        if (check(p, num) == 1) {
            /* ok */
            // printf("b:%d\n", *retSize);
            ret[*retSize] = malloc(num + 1);
            memset(ret[*retSize], 0, num + 1);
            memcpy(ret[*retSize], p, num);
            *retSize += 1;
        }
    } else {
        p[i] = 1;
        func(p, i + 1, num, retSize, ret);
        p[i] = -1;
        func(p, i + 1, num, retSize, ret);
    }
    
    return 0;
}

char ** generateParenthesis(int n, int* returnSize){
    int retSize = 0;
    int m = mutiply_n(n);
    int num = 2 * n;
    char **ret = malloc(m*sizeof(int *));
    char *p = malloc(num + 1);
    func(p, 0, num, &retSize, ret);
    // printf("a:%d\n", retSize);
    for (int i = 0; i < retSize; ++i) {
        for (int j = 0; j < num; ++j) {
            if (ret[i][j] == 1) {
                ret[i][j] = '(';
            } else {
                ret[i][j] = ')';
            }
        }
    }
    *returnSize = retSize;
    return ret;
}

```
