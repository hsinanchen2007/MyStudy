### 解题思路
由于目的是让数组各数字相等即差为0，则n-1个数加一相当于一个数减一（对差值的影响一样）故找到最小元素（第一个for循环）再求各元素与最小元差的和即可（第二个for循环）。

### 代码

```c
int minMoves(int* nums, int numsSize){
    int move=0;
    int min=nums[0];
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]<min){
            min=nums[i];
        }
    }
    for(i=0;i<numsSize;i++){
        move=move+nums[i]-min;
    }
    return move;
}
```