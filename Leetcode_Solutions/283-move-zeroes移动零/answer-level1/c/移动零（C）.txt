**双指针法**
```
void moveZeroes(int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return;
    int i, j = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[j++] = nums[i];  //这里可以优化为swap(nums[j++],nums[i]) 这样就不需要后面的for了                     
        }
    }
    for(i = j; i < numsSize; i++){
        nums[i] = 0;
    }
}
```
官方给出的优化办法果然省时：`swap(nums[j++], nums[i]);`,这样就不用了再给后面一个一个写0了。