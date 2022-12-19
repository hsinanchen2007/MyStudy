### 解题思路
时间复杂度O(n),空间复杂度O(1)
```
int majorityElement(int* nums, int numsSize){
    int count=0;
    int current=0;
    for(int i=0;i<numsSize;i++){
        if(count>0){
            if(current==nums[i]) count++;
            else count--;
        }else{
            current=nums[i];
            count++;
        }
    }
    return current;
}
```


### 代码

```c
int majorityElement(int* nums, int numsSize){
    int count=0;
    int current=0;
    for(int i=0;i<numsSize;i++){
        if(count>0){
            if(current==nums[i]) count++;
            else count--;
        }else{
            current=nums[i];
            count++;
        }
    }
    return current;
}
```