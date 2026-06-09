### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/b5a9500487ca3e29afde51833ae434c27e952e0eb2ad2cd3ce44fe87e69c4c4a-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int v;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            v = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = v;
        }
    }

    int *res = calloc(numsSize, sizeof(int));
    int res_index = 0;
    for (int i = 0; i < numsSize; i++) {
        //printf("i = %d, nums[%d] = %d\n", i, i, nums[i]);
        if (nums[i] - 1 != i) {
            res[res_index++] = i + 1;
        }
    }

    *returnSize = res_index;
    return res;
}
```