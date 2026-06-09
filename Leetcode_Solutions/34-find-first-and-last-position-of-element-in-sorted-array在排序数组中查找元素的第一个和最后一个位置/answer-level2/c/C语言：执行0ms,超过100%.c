方法1：

```
//找到左值的下标
int edgeOfLeft(int *nums, int numsSize, int target){
    int low = 0, high = numsSize, mid;

    while (low < high){
        mid = (low + high) / 2;
        if (nums[mid] == target)
            high = mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

//找到右值的下标
int edgeOfRight(int *nums, int numsSize, int target){
    int low = 0, high = numsSize, mid;

    while (low < high){
        mid = (low + high) / 2;
        if (nums[mid] == target)
            low = mid + 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low - 1;
}

/*数组中等于target的值不存在
诸如[5,7,7,8,8,10] 4, [5,7,7,8,8,10] 6, [5,7,7,8,8,10] 9, [5,7,7,8,8,10] 11这样的情况
*/
int BinarySearch(int *nums, int numsSize, int target){
    int low = 0, high = numsSize - 1, mid;

    while (low <= high){
        mid = (low + high) / 2;
        if (nums[mid] == target)
            return 1;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    res[0] = res[1] = -1;

    if (numsSize == 0 || BinarySearch(nums, numsSize, target) == 0)
        return res;
    else{
        res[0] = edgeOfLeft(nums, numsSize, target);
        res[1] = edgeOfRight(nums, numsSize, target);
    }
    return res;
}
```

或者这样简化代码量(用edgeOfRight函数也可以)
```
int edgeOfLeft(int *nums, int numsSize, int target){
    int low = 0, high = numsSize, mid;

    while (low < high){
        mid = (low + high) / 2;
        if (nums[mid] == target)
            high = mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *res = (int*)malloc(2 * sizeof(int));
    res[0] = res[1] = -1;
    int index = edgeOfLeft(nums, numsSize, target);
    if (index > numsSize - 1)
        return res;
    else if (nums[index] != target)
        return res;
    else {
        res[0] = res[1] = index;
        if (index != numsSize - 1){
            //出现[3,3,3] 3这样的测试用例时，返回[0,2]，而不是[0,1]
            while (index < numsSize){
                if (nums[index] == target)
                    res[1] = index;
                index++;
            }
        }
    }
    return res;
}
```
