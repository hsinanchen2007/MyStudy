### 解题思路
此题解是没有假设数组非空和一定存在多数元素的。
时间O(n)  空间O(1).
如果存在这个数，这个数出现的个数大于n/2，假设第一个数就是result，往后的数如果跟result相同count就++，不同就--，如果count<0,更新result。最后对于result在遍历一次看他是否真的占一半以上。
看官网题解说这个算法叫投票法。
### 代码

```c
int majorityElement(int* nums, int numsSize){
    if(numsSize<1){
        return -1;
    }
    int result = nums[0],count=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] == result){
            count++;
        }else{
            count--;
            if(count<0){
                result = nums[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == result){
            count++;
        }
    }
    return (count>numsSize/2?result:-1);
}
```