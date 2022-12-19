```
int majorityElement(int* nums, int numsSize){
    int major = nums[0], cnt = 1;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == major) cnt++;
        else if(cnt == 1){
            major = nums[i];
        }else{
            cnt--;
        }
    }
    return major;
}
```