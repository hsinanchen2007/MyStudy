### 解题思路
初次使用uthash，详细使用介绍见：https://blog.csdn.net/whatday/article/details/95926766

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 struct My_Hash{
     int key;
     int value;
     UT_hash_handle hh;
 }My_Hash_S ;

struct My_Hash* g_users = NULL;
void Hash_AddUser(int key, int value) 
{
    struct My_Hash *s;
    HASH_FIND_INT(g_users, &key, s);
    if(s == NULL){
        s = (struct My_Hash*)malloc(sizeof(struct My_Hash));
        s->key = key;
        s->value = value;
        HASH_ADD_INT(g_users, key, s);
        //printf("add key %d val %d\r\n",key, value);
    }
    return;
}
struct My_Hash* Hash_Find_user(int key) 
{   
    if(g_users == NULL) {
        return NULL;
    }
    struct My_Hash *s = NULL;
    //printf("find key %d\r\n",key);
    HASH_FIND_INT(g_users, &key, s);
    return s;
}
void Hash_DelUser(struct My_Hash* node) 
{
    HASH_DEL(g_users,node);
    free(node);
    return;
}
void Hash_DelAllUsr() 
{
    struct My_Hash * cur;
    struct My_Hash * tmp;
    HASH_ITER(hh, g_users, cur, tmp) {
        //printf("key %d,val %d\r\n", cur->key,cur->value);
        HASH_DEL(g_users, cur);
        free(cur);
    }
    return;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int findVal;
    int *retArr;
    struct My_Hash* curUsr = NULL;
    if(numsSize < 2) {
        *returnSize = 0;
        return NULL;
    }
    retArr = (int*)malloc(sizeof(int)*2);

    for(int i = 0; i < numsSize; i++) {
        findVal = target - nums[i];
        curUsr = Hash_Find_user(findVal);
        if(curUsr == NULL) {
            Hash_AddUser(nums[i], i);           
        } else {            
            retArr[1] = i;
            retArr[0] = curUsr->value;
            *returnSize = 2;
            Hash_DelAllUsr();
            return retArr;
        }
    }
    Hash_DelAllUsr();
    *returnSize = 0;
    return NULL;
}
```