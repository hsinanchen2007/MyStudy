### 解题思路
上下边界分别用二分法找到
因为一些边界的问题，不得不上下边界分别写函数求
继续研究大佬们的做法

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res={-1,-1};
        int mid,left=0,right=nums.length-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                int low=searchlow(nums,left,mid,target);
                int high=searchhigh(nums,mid,right,target);
                res[0]=low;
                res[1]=high;
                return res;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return res;
    }
    public int searchlow(int[] nums,int left,int right,int key){
        while(right>=left){
            int mid=left+(right-left)/2;
            if(nums[left]==key){
                return left;
            }
            else if(nums[left]<key){
                left+=1;
            }
            else {
                right=mid-1;
            }
        }
        return -1;
    }

    public int searchhigh(int[] nums,int left,int right,int key){
        while(right>=left){
            int mid=left+(right-left)/2;
            if(nums[right]==key){
                return right;
            }
            else if(nums[right]>key){
                right-=1;
            }
            else {
                left=mid+1;
            }
        }
        return -1;
    }

}
```