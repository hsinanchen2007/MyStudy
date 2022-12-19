### 解题思路
 从后向前，找到第一个小于前一个数的数a，然后还是从后向前，找到第一个大于这个数的数字b，交换这两个数，然后翻转从a后面的所有数字

### 代码

```c
void reverse(int* nums,int begin,int end){
    int temp;
    while(begin<end){
        temp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = temp;
        begin++;
        end--;
    }
}

void swap(int* nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
}

void nextPermutation(int* nums, int numsSize){
    int i = numsSize-2;
    // if(numsSize = 2){
    //     if(nums[0]>=nums[1])  return swap(nums,0,1);
    //     if(nums[0]<=nums[1])  return swap(nums,0,1);
    // }
    // if(numsSize = 1)
    // {
    //     return ;
    // }

    while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }

        if (i >= 0) {
            int j = numsSize - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
    reverse(nums,i+1,numsSize-1);


}
```