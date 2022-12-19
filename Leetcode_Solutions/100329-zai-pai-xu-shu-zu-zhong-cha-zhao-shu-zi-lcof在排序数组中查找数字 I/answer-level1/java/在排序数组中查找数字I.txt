### 解题思路
    先用二分查找方法找到一个Target，再依次从该位置向左、向右遍历去查找等于target的位置。

### 代码

```java
class Solution {
    public int search(int[] nums, int target) {
        if(nums==null||nums.length<=0)
            return 0;
        int idx=binarySearch(nums,0,nums.length-1,target);
        //找到一个值后再分别向左、右连续查找
        int ans=0;
        int left=idx;
        int right=idx+1;
        while(left>=0&&nums[left--]==target)
            ans++;
        while(right<nums.length&&nums[right++]==target)
            ans++;
        return ans;
    }
    private int binarySearch(int [] nums,int left,int right,int target)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
            else
                return mid;
        }
        return -1;
    }
}
```