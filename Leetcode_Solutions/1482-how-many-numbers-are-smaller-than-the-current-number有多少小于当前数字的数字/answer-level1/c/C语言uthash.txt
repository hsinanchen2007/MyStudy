### 解题思路
本题旨在熟悉uthash的使用，所以逻辑上是有些冗余的，但是是个挺好的uthash使用实例

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// iKey代表数组中的数，为key，count用于统计出现的次数
struct hash_node {
    int iKey;
    int count;
    UT_hash_handle hh;
};
// 如果使用全局变量，那么记得在函数最后调用deleteAll清除，否则跑下个用例会有问题
struct hash_node *g_hash = NULL;

// find函数
struct hash_node *findNode (int iKey) {
    struct hash_node *s;
    HASH_FIND_INT(g_hash, &iKey, s);
    return s;
}
// add函数，注意count的初始化为1，与count的增加
void addNode (int iKey) {
    struct hash_node *s;
    HASH_FIND_INT(g_hash, &iKey, s);
    if (s == NULL) {
        s = (struct hash_node *)malloc(sizeof(struct hash_node));
        s->iKey = iKey;
        s->count = 1;
        HASH_ADD_INT(g_hash, iKey, s);
    } else {
        s->count += 1;
    }
    return;
}
// deleteAll函数在所有题中只要哈希表是全局标量都是必须的
void deleteAll() {
    struct hash_node *current, *tmp;
    HASH_ITER(hh, g_hash, current, tmp) {
        HASH_DEL(g_hash, current);
        free(current);
    }
    return;
}

// 比较函数
int comp(struct hash_node *a, struct hash_node *b)
{
    return (a->iKey - b->iKey);
}

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int i;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    memset(ret, 0, sizeof(int) * numsSize);
    *returnSize = numsSize;
    // 将数组中的数字插入哈希表，统计词频
    for (i = 0; i < numsSize; i++) {
        addNode(nums[i]);
    }
    // 将哈希表排序，方便统计词频
    HASH_SORT(g_hash, comp);
    struct hash_node *current, *tmp;
    // 遍历数组
    for (i = 0; i < numsSize; i++) {
        int sum = 0;
        // 统计比目标数字小的item的数量，填充返回数组
        HASH_ITER(hh, g_hash, current, tmp) {
            if (current->iKey < nums[i]) {
                sum += current->count;
            } else if (current->iKey == nums[i]) {
                ret[i] = sum;
                break;
            }
        }
    }
    // 注意清理全局变量
    deleteAll();
    return ret;
}
```