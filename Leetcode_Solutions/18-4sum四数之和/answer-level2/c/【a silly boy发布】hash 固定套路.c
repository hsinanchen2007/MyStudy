```
#define MAXSIZE 4

typedef struct {
    int key[MAXSIZE];
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
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(nums[0]), Cmp);
    int i, j;
    int l, m;
    HashNode *tmpHashNode;
    int key[MAXSIZE];
    *returnSize = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            l = j + 1;
            m = numsSize - 1;
            while (l < m) {
                if (nums[i] + nums[j] + nums[l] + nums[m] == target) {
                    key[0] = nums[i];
                    key[1] = nums[j];
                    key[2] = nums[l];
                    key[3] = nums[m];
                    HASH_FIND(hh, g_this, key, MAXSIZE * sizeof(key[0]), tmpHashNode);
                    if (tmpHashNode == NULL) {
                        tmpHashNode = (HashNode *)malloc(sizeof(HashNode));
                        tmpHashNode->key[0] = key[0];
                        tmpHashNode->key[1] = key[1];
                        tmpHashNode->key[2] = key[2];
                        tmpHashNode->key[3] = key[3];
                        HASH_ADD(hh, g_this, key, MAXSIZE * sizeof(key[0]), tmpHashNode);
                        (*returnSize)++;
                    }
                    l++;
                    m--;
                } else if (nums[i] + nums[j] + nums[l] + nums[m] < target) {
                    l++;
                } else if (nums[i] + nums[j] + nums[l] + nums[m] > target) {
                    m--;
                }
            }
        }
    }
    int **returnVal = (int **)malloc((*returnSize) * sizeof(int *));
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    HashNode *current;
    HashNode *tmp;
    int index = 0;
    HASH_ITER(hh, g_this, current, tmp) {
        returnVal[index] = (int *)malloc(MAXSIZE * sizeof(int));
        returnVal[index][0] = current->key[0];
        returnVal[index][1] = current->key[1];        
        returnVal[index][2] = current->key[2];
        returnVal[index][3] = current->key[3];
        HASH_DEL(g_this, current);
        free(current);
        (*returnColumnSizes)[index] = 4;
        index++;
    }

    return returnVal;
}
```
