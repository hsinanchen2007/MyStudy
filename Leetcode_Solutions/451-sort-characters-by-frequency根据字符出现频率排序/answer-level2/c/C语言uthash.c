### 解题思路
利用uthash建立哈希表，根据频率排序后输出

### 代码

```c
struct hash_node {
    int iKey;   // 字符为key
    int freq;   // 字符出现的频率
    UT_hash_handle hh;
};
struct hash_node *g_hash = NULL;
// 插入逻辑
void addNode(int iKey)
{
    struct hash_node *s = NULL;
    HASH_FIND_INT(g_hash, &iKey, s);
    // 如果key值不存在则创建节点，否则修改freq
    if (s == NULL) {
        s = (struct hash_node *)malloc(sizeof(struct hash_node));
        s->iKey = iKey;
        s->freq = 1;
        HASH_ADD_INT(g_hash, iKey, s);
    } else {
        s->freq += 1;
    }
    return;
}
// 清理全局哈希变量，否则会在下一个用例处冲突
void deleteALL()
{
    struct hash_node *curt, *tmp;
    HASH_ITER(hh, g_hash, curt, tmp) {
        HASH_DEL(g_hash, curt);
        free(curt);
    }
    return;
}
// HASH_SORT比较函数，这里是根据字符出现频率降序排列
int comp(struct hash_node *a, struct hash_node *b)
{
    return b->freq - a->freq;
}

char * frequencySort(char * s){
    char *p = s;
    char *ans = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    ans[strlen(s)] = '\0';
    // 字符插入哈希表
    while(*p) {
        addNode(*p);
        p++;
    }
    // 哈希表排序
    HASH_SORT(g_hash, comp);
    int i;
    int index = 0;
    struct hash_node *curt, *tmp;
    // 遍历哈希表，填充ans对应位置
    HASH_ITER(hh, g_hash, curt, tmp) {
        for (i = 0; i < curt->freq; i++) {
            ans[index] = curt->iKey;
            index++;
        }
    }
    // 清理全局哈希变量
    deleteALL();
    return ans;
}
```