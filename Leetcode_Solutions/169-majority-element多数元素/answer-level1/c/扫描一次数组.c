### 解题思路
算法的设计思想是从前往后扫码数组元素，标记出一个可能成为主元素的元素num。然后重新计数，确认num是否为主元素。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int num = nums[0],count = 1;
    for(int i = 1; i < numsSize; i++){
        if(num==nums[i]){
            count++;
        }else if(count>0){
            count--;
        }else{
            num=nums[i];
            count=1;
        }
    }
    if(count==0)
        return -1;
    int n = 0;
    for(int i = 0; i < numsSize; i++){
        if(num==nums[i])
            n++;
    }
    if(n >= numsSize/2)
        return num;
    else
        return -1;
        
}
```