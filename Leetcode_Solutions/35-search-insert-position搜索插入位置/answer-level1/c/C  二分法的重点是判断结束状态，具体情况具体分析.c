```
int searchInsert(int* nums, int numsSize, int target){
    int left=0, right=numsSize-1, mid=0;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}
```
![image.png](https://pic.leetcode-cn.com/4664d8436d8a41b2792ae7d91f0514c4f4f30ec9cc6ed8f8d7a11b4252036be0-image.png)
