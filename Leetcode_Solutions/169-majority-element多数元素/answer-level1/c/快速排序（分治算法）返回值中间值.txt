### 解题思路
此处撰写解题思路

### 代码

```c
void quickSort(int* nums, int left, int right);

int majorityElement(int* nums, int numsSize){
    quickSort(nums, 0, numsSize - 1);
    return nums[numsSize/2];
}

void quickSort(int* nums, int left, int right){
    if(left >= right)
        return;
    int i = left, j = right;
    int key = nums[i];

    while(i < j){
        while(i < j && nums[j] > key)
            j--;
     
        if(i < j){
            nums[i] = nums[j];
            i++;
        }
            
        while(i < j && nums[i] < key)
            i++;

        if(i < j){
            nums[j] = nums[i];
            j--;
        }  
    }
    nums[i] = key;
    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}
```