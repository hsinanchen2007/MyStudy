### 解题思路
第一步：先排序，因为是串的排序，用strcmp搞定，比较难的可能是qsort的比较函数的写法；
第二步：第一步排过序后，逐一把每个目录插入到栈中（我们可以想象到，栈顶必然为根目录）；
第三步：如果在插的过程中，发现栈顶的目录是当前目录的一个子串（strstr() != NULL），就忽略当前的串；否则当前串入栈。

需要注意的是第三步，子串后紧跟的字符必须是‘/’；说明确实是一个子目录，否则就是另外一个目录了。注意场景：栈顶：a/b/c，如果待插入的目录为a/b/cd，但实际不是子目录。

效果不是最好的，没达成双100，有其他更好的算法，欢迎分享
![image.png](https://pic.leetcode-cn.com/94b5ef286b1a0e72476da067ea7b1a9fe035ddf6bc1a86c027c904555f71ade0-image.png)


### 代码

```c
int Comp2Str(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

char **removeSubfolders(char **folder, int folderSize, int *returnSize)
{
    char **ret;
    ret = malloc(sizeof(char *) * folderSize);
    *returnSize = 0;
    char *p;
    int i;

    qsort(folder, folderSize, sizeof(char *), Comp2Str);

    ret[*returnSize] = folder[0];
    *returnSize = 1;

    for (i = 1; i < folderSize; i++) {
        p = strstr(folder[i], ret[*returnSize - 1]);
        if (p == NULL) {
            ret[*returnSize] = folder[i];
            *returnSize = *returnSize + 1;
        } else if (p[strlen(ret[*returnSize - 1])] != '/') {
            ret[*returnSize] = folder[i];
            *returnSize = *returnSize + 1;
        }
    }

    return ret;
}

```