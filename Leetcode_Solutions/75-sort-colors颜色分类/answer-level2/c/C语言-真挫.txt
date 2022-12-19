### 解题思路
C语言/
qsort最简单了；
第二种方法：
先把2放到最后面，然后把1放到2的前面，很挫。。。

### 代码

```c
int Compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sortColors(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return;
    }
    
    qsort(nums, numsSize, sizeof(int), Compare);
}

```

```
void swap(int *nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void sortColors(int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return;
    }
    
    int right = numsSize - 1;
    
    // for 2
    for (int i = 0; i < right; i++) {
        while(right >= 0 && nums[right] == 2) {
            right--;
        }
        
        if (right <= 0 || right <= i) {
            break;
        }
        
        if (nums[i] == 2) {
            swap(nums, i, right);
            right--;
        } 
    }
    
    // for 1
    for (int i = 0; i < right; i++) {
        while(right >= 0 && nums[right] == 1) {
            right--;
        }
        
        if (right <= 0 || right <= i) {
            break;
        }
        if (nums[right] == 2) {
            right--;
        }
        
        if (nums[i] == 1) {
            swap(nums, i, right);
            right--;
        } 
    }
}

```