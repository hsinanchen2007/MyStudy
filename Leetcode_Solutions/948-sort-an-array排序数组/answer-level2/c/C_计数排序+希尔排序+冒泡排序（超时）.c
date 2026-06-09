执行用时 :84 ms, 在所有 C 提交中击败了98.11%的用户
内存消耗 :16.2 MB, 在所有 C 提交中击败了100.00%的用户
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 冒泡法排序超时，比较初级，轻喷
 */
/* int* sortArray(int* nums, int numsSize, int* returnSize){
    int * result = NULL;
    int i,j;
    int swap_value;
//    int error[2] = {-1,-2};
    
    if(numsSize <= 0){
        *returnSize = 2;
        return nums;
    }
    
    if(numsSize > 10000)
        numsSize = 10000;
    
    result = (int *)malloc(4 * numsSize);
    
    for(i = 0;i < numsSize;i++){
        for(j = (i + 1);j<numsSize;j++){
            if(nums[i] > nums[j]){
                swap_value = nums[j];
                nums[j] = nums[i];
                nums[i] = swap_value;
            }
        }
        
    }
    *returnSize = numsSize;
    result = nums;
        
    return result;
}
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 希尔排序，比较初级，轻喷
 */
/*
int* sortArray(int* nums, int numsSize, int* returnSize){
    int step = numsSize / 2;
    int swap_value;
    int j,i;
    
    while(step > 0){
        for(i = step; i < numsSize; i++){
            j = i;
            while(j>=step && (nums[j-step] > nums[j])){
                swap_value = nums[j-step];
                nums[j-step] = nums[j];
                nums[j] = swap_value;
                j -= step;
            }   
        }
        step /= 2;
    }
    *returnSize = numsSize;
    return nums;
}
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 计数排序，比较初级，轻喷
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    int step = numsSize / 2;
    int swap_value;
    int j,i;
    int max_value = nums[0];
    int min_value = nums[0];
    int bias = 0;
 
    if(numsSize <= 0){
        return nums;
    }   
     
    //获取数组的最大值和最小值
    for(i = 1;i < numsSize;i++){
        if(max_value < nums[i]){
            max_value = nums[i];
        }
        
        if(min_value > nums[i]){
            min_value = nums[i];
        }
    }
    
    int *bucket =(int *)malloc((max_value-min_value+1) * sizeof(int)); 
    memset(bucket,0,(max_value-min_value+1) * sizeof(int));
    
    bias = 0 - min_value;//make sure bucket starts from 0
    
    for(i = 0;i < numsSize;i++){
        bucket[nums[i] + bias]++;
    }
    
    i = 0;
    j = 0;
    while(i < numsSize){
        if(bucket[j] > 0){
            nums[i] = j - bias;
            i++;
            bucket[j]--;
        }
        else{
            j++;
        }
    }   

    *returnSize = numsSize;
    return nums;
}