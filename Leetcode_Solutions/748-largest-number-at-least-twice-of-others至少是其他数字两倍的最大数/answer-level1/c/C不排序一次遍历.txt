### 解题思路
![Snipaste_2020-03-10_14-44-58.png](https://pic.leetcode-cn.com/432447bfcce83cd2ec7c605324414aaf33d0e504b62e35fbe36a22f7ef60893c-Snipaste_2020-03-10_14-44-58.png)
一次遍历数组，同时找出最大和次大的元素

### 代码

```c
int dominantIndex(int* nums, int numsSize){
    if(numsSize==1) return 0;
    int max=0,secmax=0,maxindex=0;
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]>max){//更新最大
            secmax=max;
            maxindex=i;
            max=nums[i];
        }else if(nums[i]>secmax){//更新次大
            secmax=nums[i];
        }
    }
    if(max<2*secmax)
        return -1;
    return maxindex;

}
```