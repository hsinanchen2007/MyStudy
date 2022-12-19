```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *returnedArray = (int *)malloc(numsSize * sizeof(int)); // 保存结果
    int *indexArray = (int *)malloc(numsSize * sizeof(int)); // 下标栈：保存入栈元素的下标
    int *stack = (int *)malloc(numsSize * sizeof(int)); //单调栈
    int temp = -1; // 栈顶指针
    int MaxIdx;

    *returnSize = numsSize;

    if (numsSize == 0) {
        return returnedArray;
    }


    for (int i = 0; i < numsSize; i++) { // 全部元素第一次入栈（不循环）
        
        while (temp > -1 && nums[i] > stack[temp]) {
            returnedArray[indexArray[temp]] = nums[i];
            temp--;
        }
        stack[++temp] = nums[i]; // 
        indexArray[temp] = i;
    }

    MaxIdx = indexArray[temp]; // 栈顶元素的下标值

    for (int i = 0; i < MaxIdx; i++) { // 第一次入栈后没有找到nge的元素，循环从头开始找；此次不再有入栈操作，仅仅将找到nge的元素和其对应的下标出栈
        while (temp > -1 && nums[i] > stack[temp]) {
            returnedArray[indexArray[temp]] = nums[i];
            temp--;
        }
    }

    while (temp > -1) { // 没有对应nge的元素输出为-1
        returnedArray[indexArray[temp]] = -1;
        temp--;
    }

    free(indexArray);
    free(stack);

    return returnedArray;

}
```
