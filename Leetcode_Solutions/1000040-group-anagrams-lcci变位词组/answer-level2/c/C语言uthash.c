### 解题思路
通过在哈希表节点的数据结构中维护一个字符串数组来解决问题。

建立一个哈希表，key值是经过排序的字符串，此外另有两个值：一个是字符串数组，用来存储所有变位词组（也就是说排序后相同的数组都会在同一个哈希节点中）；另外一个值是数组大小，用来给returnColumnSizes赋值。

在向哈希表添加元素的过程中，先要复制对应的字符串，然后将副本字符串qsort排序，副本字符串作为key值向哈希表进行插入。

然后需要将原字符串加入到该哈希表维护的字符串数组中，同时该数组的大小+1。

然后哈希表的大小就是returnSize，遍历哈希表得到每个节点的字符串数组，组合起来就能得到待返回的字符串数组的数组了。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct hash_node {
    char pcKey[100];    // 用排序后的字符串作为key
    char **valueStrs;   // 字符串数组，存储同一类型下的所有变位词组
    int vStrsNum;       // 上述字符串数组大小
    UT_hash_handle hh;
};
// 全局变量hash表，注意最后要释放，否则在跑下一个用例时会冲突
struct hash_node *g_hash = NULL;
// 字符串qsort比较函数
int comp(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}
// 向哈希表插入数据
void addNode(char *name)
{   
    // 拷贝原始字符串，并对副本进行排序，作为key
    char *temp = (char *)malloc(sizeof(char) * 100);
    strcpy(temp, name);
    qsort(temp, strlen(temp), sizeof(char), comp);

    // 插入逻辑
    struct hash_node *s = NULL;
    HASH_FIND_STR(g_hash, temp, s);
    if (s == NULL) {
        // 申请内存后将原始字符串插入到节点维护的字符串数组中，以排序后的字符串作为key插入哈希表
        s = (struct hash_node *)malloc(sizeof(struct hash_node));
        strcpy(s->pcKey, temp);
        s->vStrsNum = 1;
        s->valueStrs = (char **)malloc(sizeof(char *) * 100);
        s->valueStrs[0] = (char *)malloc(sizeof(char) * 100);
        strcpy(s->valueStrs[0], name);
        HASH_ADD_STR(g_hash, pcKey, s);
    } else {
        // 如果哈希表的key已经存在，那么只要维护这个节点的字符串数组和代表大小的变量即可
        s->valueStrs[(s->vStrsNum)] = (char *)malloc(sizeof(char) * 100);
        strcpy(s->valueStrs[(s->vStrsNum)], name);
        s->vStrsNum += 1;
    }
    return;
}
// 全局变量清理函数
void deleteAll()
{
    struct hash_node *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    // 内存申请多一点
    char ***ret = (char ***)malloc(sizeof(char **) * 10000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    int i;
    // 将strs中的字符串插入哈希表
    for (i = 0; i < strsSize; i++) {
        addNode(strs[i]);
    }
    // 统计哈希表item数量作为returnSize
    *returnSize = HASH_COUNT(g_hash);
    struct hash_node *current, *tmp;
    i = 0;
    // 遍历哈希表，取其中每个节点的字符串作为返回值的一条数据，字符串数组大小作为returnColumnSizes
    HASH_ITER(hh, g_hash, current, tmp) {
        ret[i] = current->valueStrs;
        (*returnColumnSizes)[i] = current->vStrsNum;
        i++;
    }
    // 清理哈希表全局变量
    deleteAll();
    return ret;
}
```