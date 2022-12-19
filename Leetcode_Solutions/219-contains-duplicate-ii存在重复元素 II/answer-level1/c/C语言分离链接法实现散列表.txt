### 解题思路
见代码注释

### 代码

```c
typedef struct node {
    int idx;                    /* 存放数组下标 */
    int val;                    /* 存放数值 */
    struct node *next;          /* next指针解决冲突 */
} hashMap;

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    hashMap **hash = (hashMap**)calloc(numsSize, sizeof(hashMap *));
    for (int i = 0; i < numsSize; i++) {    /* hash[i]相当于头结点（不存放信息） */
        hash[i] = (hashMap*)malloc(sizeof(hashMap));
        hash[i]->next = NULL;
    }
    
    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i] % numsSize);    /* 哈希函数 */
        hashMap *p = hash[index];
        
        while (p->next && p->next->val != nums[i])
            p = p->next;
        
        if (p->next && abs(p->next->idx - i) <= k)
            return true;                        /* 符合条件 */
        else if (p->next)                       /* 下标之差超过k，更新该数字的下标，继续搜索 */
            p->next->idx = i;
        else {                                  /* 该数字还没出现过 */
            p->next = (hashMap*)malloc(sizeof(hashMap));
            p->next->val = nums[i];
            p->next->idx = i;
            p->next->next = NULL;
        }
    }
    
    return false;
}
```