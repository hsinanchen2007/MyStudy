### 解题思路
把和看成前n-1项的和以及新加入的项之和，如果说前n-1项和小于0，就用新加入的项代替。
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int sum = 0,max=nums[0];
    for(int i = 0; i < numsSize; i++){
        if(sum > 0){
            sum += nums[i];
        }else{
            sum = nums[i];
        }if(sum > max){
            max = sum;
        }
    }
    return max;
}
```