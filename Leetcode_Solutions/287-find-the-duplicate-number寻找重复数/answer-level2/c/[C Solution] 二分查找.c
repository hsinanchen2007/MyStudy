### 解题思路
此处撰写解题思路

1-n 的区间 二分查找

### 代码

```c
int findDuplicate(int* nums, int numsSize){
    if(numsSize <= 0){
        return 0;
    }
    int left = 0 , right = numsSize - 1 ;

    while(left < right){
        int mid = (left + right) /2 ;
        int cnt = 0;
        for(int i = 0; i < numsSize; i++){
            if(nums[i] <= mid){
                cnt++;
            }
        }
        if(cnt > mid ){
            right =  mid;
        }else{
            left = mid + 1;
        }
    }

    return left;
}
```