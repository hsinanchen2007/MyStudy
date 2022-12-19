### 解题思路
Hash+暴力

### 代码
Hash
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* arr = (int*)malloc(sizeof(int) * 101);
    int* ans = (int*)malloc(sizeof(int) * numsSize);

    memset(arr, 0, sizeof(int) * 101);
    memset(ans, 0, sizeof(int) * numsSize);
    printf("%d\n", 123);
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]]++;
    }
   
    int sum = 0;
 
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < nums[i]; j++) {      
            sum += arr[j];         
        }      
        ans[i] = sum;
        sum = 0;
    }
    *returnSize = numsSize;
    return ans;
}

暴力
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    memset(arr, 0, sizeof(int) * numsSize);
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (nums[i] > nums[j]) {
                count++;
            }
            
        }
        arr[i] = count;
        count = 0;
    }
    *returnSize = numsSize;
    return arr;
}
```