### 解题思路
算出0到n个数本应该有的总和减去实际的总和即可
不过我本以为这个代码会溢出的因为(numsSize+1)*numsSize可能很大

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int target=(numsSize+1)*numsSize/2,sum=0,i=0;
    while(i<numsSize){
        sum+=nums[i++];
    }
    return target-sum;
}
```