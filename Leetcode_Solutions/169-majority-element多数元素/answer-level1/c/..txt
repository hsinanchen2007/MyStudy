### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int count = 1;
    int value = nums[0];
    if(numsSize == 0) return 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == value){
            count++;
        }else{
            count--;
            if(count == 0){
                value = nums[i];
                count = 1;
            }
        }
    }
    return value;
}
```