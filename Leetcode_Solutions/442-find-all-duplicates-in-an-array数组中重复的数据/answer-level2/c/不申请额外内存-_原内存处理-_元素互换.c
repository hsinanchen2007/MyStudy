/**
 * Note: The returned array must be malloced, assume caller calls free().
 nums[i]的值用来表示i的出现次数，-1为一次，-2为两次
 从0开始，每次让把值nums[i]在nums中的位置-1，同时把之前的值放回到num[i]中
 [ 4, 3, 2, 7, 8, 2, 3, 1]
 [ 7, 3, 2,-1, 8, 2, 3, 1]
 [ 3, 3, 2,-1, 8, 2,-1, 1]
 [ 2, 3,-1,-1, 8, 2,-1, 1]
 [ 3,-1,-1,-1, 8, 2,-1, 1]
 [ 0,-1,-2,-1, 8, 2,-1, 1]
 [ 0,-1,-2,-1, 1, 2,-1,-1]
 [-1,-1,-2,-1, 0, 2,-1,-1]
 [-1,-2,-2,-1, 0, 0,-1,-1]
 特殊情况： 
 [0, 0, 3, 4, 5]
 [0, 0,-1,-1,-1]
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int tmp;
    int count = 0;
    int *results = NULL;
    if (numsSize <= 1) {
        * returnSize = 0;
        return NULL;
    }
    results = malloc(sizeof(int) * numsSize);
    memset(results, 0, sizeof(results));
    for (i = 0; i < numsSize;) {
        // 已经查过了，不用在查了
        if(nums[i] <= 0) {
            i++;
            continue;
        }
        // 把nums[i]对应的位置写成-1，对应位置的数据写到nums[i]上
        if (i == nums[i] - 1) {
            nums[i] = - 1;
            i++;
            continue;
        }
        tmp = nums[nums[i] - 1];  //1
        if (tmp <= 0) {
            nums[nums[i] - 1] -= 1;
            nums[i] = 0;
        } else { // 把索引nums[i] -1的位置内容置-1
            if (nums[i] == (i + 1)){
                nums[nums[i] - 1] = -1;
            } else {
                nums[nums[i] - 1] = -1;
                nums[i] = tmp;
            }              
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == -2) {
            results[count++] = i+1;
        }
    }
    if (count == 0) {
        *returnSize = 0;
        return NULL;  
    } else {
        *returnSize = count;
        return results; 
    } 
       
}