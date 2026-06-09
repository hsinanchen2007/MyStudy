思路：
直接写找窗口内最大值的函数findMax，遍历数组时每次调用，
注意数组为空的情况returnSize置0，返回NULL
```
int findMax(int *array, int start, int end){
    int max = array[start];
    for(int i = start; i <= end; i++){
        if(array[i] >= max){
            max = array[i];
        }
    }
    return max;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(nums == NULL || numsSize == 0){
        *returnSize = 0;
        return NULL;
    }
    int *ret = malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;
    for(int i = 0; i < *returnSize; i++){
        ret[i] = findMax(nums, i, i + k - 1);
    }
    return ret;
}
```
