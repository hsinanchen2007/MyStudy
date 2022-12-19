

```
struct hash_table{
    int key;
    int value;
    UT_hash_handle hh;
};
typedef struct hash_table* hash_ptr;

hash_ptr find_node(hash_ptr table, int key)
{
    if(!table)
        return NULL;
    hash_ptr s;
    HASH_FIND_INT(table, &key, s);
    return s;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, delta;
    int *p = NULL;
    hash_ptr elem, table = NULL;
    for(i = 0; i < numsSize; i++){
        delta = target - nums[i];
        hash_ptr node = find_node(table, delta);
        if(node){
            p = (int*)malloc(sizeof(int) * 2);
            *returnSize = 2;
            p[1] = i;
            p[0] = node->value;
            return p;
        }
        elem = (hash_ptr)malloc(sizeof(struct hash_table));
        elem->key = nums[i];
        elem->value = i;
        HASH_ADD_INT(table, key, elem);
    }
    *returnSize = 0;
    return p;
}
```
