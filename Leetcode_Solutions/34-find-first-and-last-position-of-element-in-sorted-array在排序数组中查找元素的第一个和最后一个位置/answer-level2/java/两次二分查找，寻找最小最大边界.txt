### 解题思路
此处撰写解题思路
循环两次，二分查找左侧区间跟右侧区间，
左侧区间：跟二分查找大部分相同，不同的是当匹配目标值时，先不返回，而是继续缩减右侧区间，这样子左侧不便，右侧缩减，如果左侧还有目标值，那么就会继续二分查找，从而最终得到left>right的跳出判断，此时因为之前的right=mid-1,所以left就是mid,返回left就是返回左侧，

右侧区间：同样，当相同的时候，缩减左侧区间，left=mid+1，
但是这里因为left>right时调处循环，所以因为left=mid+1，所以left是比右侧区间大一的，所以要用right
或者left-1，记忆的话，就记住left，跟left-1分别是左侧区间跟右侧区间。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len=nums.length;
        int left=0;
        int right=nums.length-1;
        while(left<=right)
        {
            int mid=left + (right-left)/2;
            if(nums[mid]>=target)
                right=mid-1;
            else
                left=mid+1;

        }
        int left_index=0;
        if(left==len || nums[left]!=target)
            left_index=-1;
        else
            left_index=left;
        left=0;
        right=nums.length-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<=target)
                left=mid+1;
            else
                right=mid-1;
        }
//
//        left=left-1;
//        if(left<0)
//            left=-1;
        left=right;
        if(left<0)
            left=-1;
         else if(left==len || nums[left]!=target)
            left=-1;
        int[] res= new int[2];
        res[0]=left_index;
        res[1]=left;
        return res;
    }
}

```