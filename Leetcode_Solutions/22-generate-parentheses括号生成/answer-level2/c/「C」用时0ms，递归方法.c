### 解题思路

用C语言比较麻烦的就是需要提前分配内存，所以下面这两行用于提前把内存给分配好，包括最终结果和每个组合的大小。

```c
    char *s = malloc(sizeof(char) * n * 2 +1);
    *returnSize = 0; //默认是0
    int initSize = comb(n);
    char **ret = malloc(sizeof(char*) * initSize);
```

用于提前分配的大小可能是比较大的，因此returnSize每次确定组合后增1，同时s是一个固定内存位置，需要重新分配一份内存用于存放字符。

```c
        s[left+right] = '\0';
        ret[*returnSize] = strdup(s);
        *returnSize = *returnSize + 1;
```

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void generate(int n, int left, int right, char** ret, char *s, int*returnSize){
    if (left == n && right == n){
        s[left+right] = '\0';
        ret[*returnSize] = strdup(s);
        *returnSize = *returnSize + 1;
        return ;
    }
    if (left < n){
        s[left+right] = '(';
        generate(n, left+1, right, ret, s, returnSize);
    }
    if (right < left){
        s[left+right] = ')';
        generate(n, left, right+1, ret, s, returnSize);
    }
    return ;

}

int comb(int n){
    int ret = 1;
    for (int i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}

char ** generateParenthesis(int n, int* returnSize){
    char *s = malloc(sizeof(char) * n * 2 +1);
    *returnSize = 0; //默认是0
    int initSize = comb(n);
    char **ret = malloc(sizeof(char*) * initSize);
    generate(n, 0, 0, ret, s, returnSize);
    return ret;

}
```