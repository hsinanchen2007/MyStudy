### 解题思路
1. 使用UTHASH。
2. leetcode给的例子只有整形。附一个更全的例子。

### 代码

```c

typedef struct hashNode {
    int val;
    UT_hash_handle hh;
} HASHNODE;

bool containsDuplicate(int* nums, int numsSize){
    HASHNODE *htable = NULL;
    HASHNODE *tmp;

    int i;
    for (i = 0; i < numsSize; i++) {
        HASH_FIND_INT(htable, &nums[i], tmp);
        if (tmp) return true;

        tmp = (HASHNODE*)malloc(sizeof(HASHNODE));
        tmp->val = nums[i];
        HASH_ADD_INT(htable, val, tmp);
    }

    HASHNODE *curr;
    HASH_ITER(hh, htable, curr, tmp) {
        HASH_DEL(htable, curr);
        free(curr);
    }
    return false;
}
```


```c
struct node {
    int userid; /* int type key */
    char name[10]; /* string type key */
    char *address; /* pointer type key */
    void *ptr; /* unique pointer tpe key */
    UT_hash_handle hh;
};

struct node *htable;
struct node *elem, *tmp;

HASH_COUNT(htable);
HASH_ITER(hh, htable, elem, tmp){}
HASH_DEL(htable, elem);



HASH_ADD_INT(htable, userid, elem);
HASH_FIND_INT(htable, &id, elem);

HASH_ADD_STR(htable, name, elem);
HASH_FIND_STR(htable, "aaa", elem);

HASH_ADD_KEYPTR(hh, htable, elem->address, strlen(elem->address), elem); // special
HASH_FIND_STR(table, "aaa", elem);

HASH_ADD_PTR(htable, ptr, elem);
HASH_FIND_PTR(htable, &someaddr, elem);

```