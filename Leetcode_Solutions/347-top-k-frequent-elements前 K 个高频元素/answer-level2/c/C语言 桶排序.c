![image.png](https://pic.leetcode-cn.com/3f75bf1d45c45f94ae212c01d83370ed662898d0b9cb449b7140ee9f05d746b6-image.png)

```
#define  MAX_SIZE 100000
#define  MAX_SIZE1 1000
int Comp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), Comp);
    int *bk[MAX_SIZE] = {0};
    int id[MAX_SIZE] = {0};
    memset(bk, 0, MAX_SIZE * sizeof(int*));
    int index = 0;
    int count[MAX_SIZE] = {0};
    count[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count[index]++;
        } else {
            count[i]++;
            index = i;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (count[i] == 0) {
            continue;
        }
        if (bk[count[i]] == NULL) {
            bk[count[i]] = (int*)malloc(MAX_SIZE1 * sizeof(int));
            memset(bk[count[i]], -1, MAX_SIZE1 * sizeof(int));  
        }
        bk[count[i]][id[count[i]]++] = i;
    }
    int *res = (int*)malloc(k * sizeof(int));
    
    int j = 0;
    for (int i = numsSize; i >= 0; i--) {
        if (bk[i] != NULL) {
            while (--id[i] >= 0) {
                res[j++] = nums[bk[i][id[i]]];    
                if (j == k) {
                    break;
                }
            }
            if (j == k) {
                break;
            }
        }
        
    }
    *returnSize = k;
    return res;
}
```
