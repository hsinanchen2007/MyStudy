### 解题思路
hash、并查集都是轮子，还算比较通用，各位自行取用
思路见注释

### 代码

```c
#include <stdio.h>
//#include "uthash.h"

static int *g_father;
static int *g_count;

static int FindFather(int n)
{
    if (g_father[n] == n) {
        return n;
    }

    return g_father[n] = FindFather(g_father[n]);
}

static void SetUnion(int a, int b)
{
    int aFather, bFather;
    aFather = FindFather(a);
    bFather = FindFather(b);

    /* 找小的当爹 */
    if (aFather < bFather) {
        g_father[bFather] = aFather;
    } else if (bFather < aFather) {
        g_father[aFather] = bFather;
    }
}

static void Init(int n)
{
    int i;

    if (n == 0) {
        return 0;
    }
    /* 动态维护集合大小，本题用不到 */
    g_count = (int *)calloc(1, sizeof(int) * (n + 1));
    g_father = (int *)calloc(1, sizeof(int) * (n + 1));

    for (i = 0; i < n; i++) {
        g_father[i] = i;
        g_count[i] = 1;
    }
}

struct HashNode {
    int num;
    int index;//这里依据题意可以放所需的信息，比如index、cnt等
    UT_hash_handle hh;
};

static struct HashNode *g_users;

static bool AddNum(int num, int index)
{
    struct HashNode *p;    
    HASH_FIND_INT(g_users, &num, p);
    if (p != NULL) {
        return false;
    }
    p = (struct HashNode *)calloc(1, sizeof(struct HashNode));
    p->num = num;
    p->index = index;
    HASH_ADD_INT(g_users, num, p);
    return true;
}

static bool FindNum(int num, int *index)
{
    struct HashNode *p;
    HASH_FIND_INT(g_users, &num, p);
    if (p == NULL) {
        return false;
    }
    *index = p->index;
    return true;
}

int longestConsecutive(int* nums, int numsSize){
    
    int *leadCnt = (int *)calloc(1, sizeof(int) * (numsSize + 1));
    int i, aIndex, bIndex, maxCnt;

    g_users = NULL;
    Init(numsSize);

    for (i = 0; i < numsSize; i++) {
        /* 如果add成功了，去找+1、-1的数字有没有出现过；如果没有添加成功，说明这个数字是重复数字，跳过 */
        if (!AddNum(nums[i], i)) {
            continue;
        }
        if (FindNum(nums[i] - 1, &aIndex)) {
            SetUnion(i, aIndex);
        }
        if (FindNum(nums[i] + 1, &bIndex)) {
            SetUnion(i, bIndex);
        }
    }
    /* 路径压缩，简单的办法就是每个都在搜索一遍 */
    for (i = 0; i < numsSize; i++) {
        FindFather(i);
    }

    maxCnt = 0;
    /* 统计每个集合的成员个数 */
    for (i = 0; i < numsSize; i++) {
        leadCnt[g_father[i]]++;
    }
    /* 找到最大成员个数的集合 */
    for (i = 0; i < numsSize; i++) {
        if (maxCnt < leadCnt[i]) {
            maxCnt = leadCnt[i];
        }
    }
    return maxCnt;
}
```