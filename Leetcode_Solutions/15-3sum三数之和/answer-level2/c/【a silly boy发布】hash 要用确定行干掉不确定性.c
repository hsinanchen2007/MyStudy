```
#define COLSIZE 3

typedef struct {
    int key[3];
    int val;
    UT_hash_handle hh;
} HashNode;
HashNode *g_this = NULL;

int Cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(nums[0]), Cmp);
    *returnSize = 0;
    int i;
    int l;
    int m;
    int *key = (int *)malloc(3 * sizeof(int));
    HashNode *tmpHashNode;
    for (i = 0; i < numsSize; i++) {
        l = i + 1;
        m = numsSize - 1;
        while (l < m) {
            if ((nums[i] + nums[l] + nums[m]) == 0) {
                key[0] = nums[i];
                key[1] = nums[l];
                key[2] = nums[m];
                HASH_FIND(hh, g_this, key, 3 * sizeof(key[0]), tmpHashNode);
                if (tmpHashNode == NULL) {
                    tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
                    tmpHashNode->key[0] = key[0];
                    tmpHashNode->key[1] = key[1];
                    tmpHashNode->key[2] = key[2];
                    HASH_ADD(hh, g_this, key, 3 * sizeof(key[0]), tmpHashNode);
                    (*returnSize)++;
                }
                l++;
                m--;
            } else if ((nums[i] + nums[l] + nums[m]) < 0) {
                l++;
            } else if ((nums[i] + nums[l] + nums[m]) > 0) {
                m--;
            }
        }
    }
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    HashNode *current;
    HashNode *tmp;
    int index = 0;
    int **returnVal = (int **)malloc((*returnSize) * sizeof(int *));
    HASH_ITER(hh, g_this, current, tmp) {
        returnVal[index] = (int *)malloc(COLSIZE * sizeof(int));
        returnVal[index][0] = current->key[0];
        returnVal[index][1] = current->key[1];
        returnVal[index][2] = current->key[2];
        (*returnColumnSizes)[index] = 3;
        HASH_DEL(g_this, current);
        free(current);
        index++;
    }

    return returnVal;
}
```
