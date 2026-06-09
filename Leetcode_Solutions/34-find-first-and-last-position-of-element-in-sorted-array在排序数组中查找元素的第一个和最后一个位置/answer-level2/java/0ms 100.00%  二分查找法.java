### 解题思路
首先对数组长度为0和1的进行判断，可以直接返回结果。对于长度大等于2的数组，我们需要对其进行二分查找。
找出下标后先填入res中，这样做的目的是为了防止index落在头或尾（特别是尾，头部还有个默认值0）导致没有进入后续两个while。while里做的其实就是对剩余的左半部分和右半部分进行二分查找，从而找出左右边界。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[]res=new int[2];
        int n=nums.length;
        if(n==0) return new int[]{-1,-1};
        if(n==1) return nums[0]==target?new int[]{0,0}:new int[]{-1,-1};
        int index=search(nums,0,n-1,target);
        if(index==-1) return new int[]{-1,-1};
        res[0]=index;
        res[1]=index;
        int l=0,r=index-1;
        while(l<=r){
            int i=search(nums,l,r,target);
            if(i==-1){
                break;
            }else{
                res[0]=i;
                r=i-1;
            }
        }
        l=index+1;
        r=n-1;
        while(l<=r){
            int i=search(nums,l,r,target);
            if(i==-1){
                break;
            }else{
                res[1]=i;
                l=i+1;
            }
        }
        return res;
    }
    public int search(int[]nums,int start,int end,int target){

        int left=start,right=end;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }else if(target<nums[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return -1;
    }

}
```