### 解题思路
首先二分找到第一个target，索引为i,之后在两边分别寻找左边界以及右边界

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        int l=0,r=nums.length-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else if(nums[mid]>target){
                r=mid-1;
            }else{
                return findR(nums,mid+1,r,target)-findL(nums,l,mid-1,target)+1;
            }
        }
        return 0;
    }
    public int findL(int[] nums,int l,int r,int target){
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return r+1;
    }
    public int findR(int[] nums,int l,int r,int target){
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l-1;
    }
}
```