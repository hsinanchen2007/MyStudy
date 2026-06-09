### 解题思路
从后往前找到第一个非递增的数字a,可能有两种情况。
1.如果遍历完数组整个数组都是从后往前增序，那么直接逆转整个数组。
2.如果找到了数字a，在从后往前找到第一个大于数字a的数字b，两者交换，此时b后边的数字仍然是从后往前递增的，将b后的数字逆序。
此处撰写解题思路

### 代码

```c
void nextPermutation(int* nums, int numsSize){
    if(numsSize < 2){
        return;
    }
    int i=numsSize-1,j=numsSize-1;
    while(i>0){
        if(nums[i] > nums[--i]){
            break;
        }
    }
    if(i==0 && nums[i]>=nums[i+1]){             //1.
        for(i=0,j=numsSize-1;i<j;i++,j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        } 
    }else{                                       //2.
        for(j=numsSize-1;nums[j]<=nums[i];j--);
        int temp = nums[i];
        nums[i++] = nums[j];
        nums[j] = temp;
        for(i,j=numsSize-1;i<j;i++,j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
```