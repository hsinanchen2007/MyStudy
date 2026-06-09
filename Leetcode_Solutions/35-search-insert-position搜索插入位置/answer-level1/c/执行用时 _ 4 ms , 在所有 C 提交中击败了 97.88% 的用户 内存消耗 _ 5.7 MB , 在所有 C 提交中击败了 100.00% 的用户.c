### 解题思路
此处撰写解题思路

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int left = 0,right = numsSize - 1;
    int mid = right - (right -left) / 2;
    while(left <= right){
        if(nums[mid] == target ){
            return mid;
        }else if(nums[mid] < target){
            left = mid +1;  
        }else{
            right = mid -1;
        }
        mid = right - (right -left ) / 2;
    }
    /*前面就是二分算法，只是加了left 可以 等于right的条件*/
    return left;
    /*出循环的原因就是right+1=left，会有三种情况； 
    *right = -1,left = 0;此时返回0,就是left；
    *left = numsSize,right = numsSize - 1,返回numsSize，就是left；
    *left和right在中间，right标记最大的小于target数字的下标，left标记最小的大于target数字的下标，返回left
    *综上返回left
    */
}
```