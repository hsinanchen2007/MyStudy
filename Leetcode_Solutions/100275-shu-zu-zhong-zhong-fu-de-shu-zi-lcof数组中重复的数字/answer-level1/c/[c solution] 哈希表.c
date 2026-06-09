### 解题思路
此处撰写解题思路

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    if(numsSize <= 0 ){
        return -1;
    }
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    memset(arr,sizeof(bool)*numsSize , 0 );

    for(int i = 0; i < numsSize ; i++){
        if(arr[nums[i]] == 1){
            return nums[i];
        }else{
            arr[nums[i]] = 1;
        }
    }
    return -1;
}
```