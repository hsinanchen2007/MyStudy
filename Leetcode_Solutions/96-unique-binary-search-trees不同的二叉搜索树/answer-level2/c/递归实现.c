### 解题思路
思路
1 2 3 4 5
1作为根时的数量有（0） * （3 4 5）种办法
2作为根时的数量有（1） * （3 4 5）种办法
3作为根时的数量有（1 2） * （4 5）种办法
一次类推，中间记录已经算过的值，不要重复计算。

### 代码

```c
int FindTree(int n, int *tree)
{
    int  count = 0;
    if (n < 3) {
        return tree[n];
    }
    // 已经计算过，不重复计算
    if (tree[n] != 0) {
        return tree[n];
    }
    for (int i = 1; i <= n; i++) {
        count += FindTree(i-1, tree) * FindTree(n-i, tree);       
    }
    tree[n] = count;
    return count;
}
int numTrees(int n){
    int count = 0;
    int* tree = NULL;

    if (n < 3) {
        return n;
    }

    tree = (int*)calloc(n+1, sizeof(int));
    tree[0] = 1;
    tree[1] = 1;
    tree[2] = 2;

    count = FindTree(n, tree);
    free(tree);
    return count;
}
```