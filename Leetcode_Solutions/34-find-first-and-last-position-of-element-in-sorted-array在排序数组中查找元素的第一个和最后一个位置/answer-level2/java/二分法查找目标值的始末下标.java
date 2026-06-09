### 解题思路
在二分查找中，如果中间值等于目标值，则从当前位置向左右查找。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len=nums.length;
        if(len==0)
            return new int[]{-1,-1};
        int[] res=new int[2];
        int l=0;
        int r=len-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(nums[mid]==target){
                int i=mid;
                while(--i>=0&&nums[i]==target);
                res[0]=i+1;
                int j=mid;
                while(++j<len&&nums[j]==target);
                res[1]=j-1;
                return res;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return new int[]{-1,-1};
    }
}
```