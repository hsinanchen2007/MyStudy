### 解题思路
窗口法：低指针是数组中最小的数（numbers[low]=numbers[0]），高位是比target小的最大的数numbers[high]<target&&numbers[high+1]>target)

如果 low和high位置上的数字加起来大于target，高位缩小窗口（high--）；如果小于targe，低位缩小窗口（low++）；如果等于target，返回low 和 high

注意返回的数组要升序
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){

    int low=0,high=numbersSize-1;
    while(numbers[high]>target)--high;

    while(numbers[low]+numbers[high]!=target)
        if(numbers[low]+numbers[high]>target) 
            --high;
        else 
            ++low;

    int* result=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    result[0]=low<=high?low+1:high+1;
    result[1]=low<=high?high+1:low+1;
    return result;
}
```