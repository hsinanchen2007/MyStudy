### 解题思路
既然涉及已排序数组的搜索，那自然而然想到利用二分法加快搜索速度。
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :39.3 MB, 在所有 Java 提交中击败了5.03%的用户

### 代码

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        int res=binarySearch(target,nums,0,nums.length-1);
        if(res<=0){
            if(nums[-res]>=target)
                return -res;
            else 
                return -res+1;
        }else
            return res;
    }

    int binarySearch(int target,int[] nums,int low,int high){
        if(low==high){
            if(nums[low]==target)
                return low;
            else
                return -low;
        }
        if(nums[(low+high)/2]>target)
            return binarySearch(target,nums,low,high-1);
        if(nums[(low+high)/2]<target)
            return binarySearch(target,nums,low+1,high);
        else
            return (low+high)/2;
    }
}
```