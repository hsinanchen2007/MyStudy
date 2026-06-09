### 解题思路
此处撰写解题思路

### 代码

```c
int majorityElement(int* nums, int numsSize){
    if(numsSize <= 0){
        return -1;
    }
    int count = 0 , num = 0;
    for(int i = 0 ; i < numsSize ; i++){
        if(count == 0 ){
            num = nums[i];
            count++;
        }else{
            (num == nums[i]) ? count++ : count--;
        }
    }
    return num;
}
```