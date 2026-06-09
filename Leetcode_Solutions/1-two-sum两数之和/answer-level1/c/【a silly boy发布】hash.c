```
typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} HashMap;

HashMap *g_this = NULL;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    HashMap *tmpHashMap;
    int key;
    *returnSize = 2;
    int *returnVal = (int *)malloc((*returnSize) * sizeof(int));
    memset(returnVal, 0, (*returnSize) * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        returnVal[0] = i;
        key = target - nums[i];
        HASH_FIND_INT(g_this, &key, tmpHashMap);
        if (tmpHashMap == NULL) {
            tmpHashMap = (HashMap *)malloc(sizeof(HashMap));
            tmpHashMap->key = nums[i];
            tmpHashMap->index = i;
            HASH_ADD_INT(g_this, key, tmpHashMap);
        } else {
            returnVal[1] = tmpHashMap->index;
            break;
        }
    }
    HashMap *current;
    HashMap *tmp;
    HASH_ITER(hh, g_this, current, tmp) {
        HASH_DEL(g_this, current);
        free(current);
    }

    return returnVal;
}
```
