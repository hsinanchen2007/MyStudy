### 解题思路
此处撰写解题思路

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    for(int j = 0; j < numsSize; j++){
        if(nums[j] != val){
            nums[i] = nums[j];
            ++i;
        }
    }
    return i;
}
/*int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int j = numsSize - 1;
    int num = 0;
    if(nums == NULL || (numsSize == 1 && nums[numsSize - 1] == val)){
        return 0;
    }
    while(j > i){
        if((nums[i] == val) && (nums[j] != val)){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
        if(nums[i] == val && nums[j] == val){
            j--;
        }
        if (nums[i] != val && nums[j] != val){
            i++;
        }
        if(nums[i] != val && nums[j] == val){
            i++;
            j--;
        }
    }

    for(int k = numsSize -1; k>= 0; --k){
        if(nums[k] == val){
            num++;
        }
    }
    return numsSize - num;
}*/

```