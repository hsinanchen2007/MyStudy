这道题不难，居然很多人直接线性遍历都能1ms…… 不过理论上来说二分查找复杂度低一点就是。

执行用时 : 1 ms, 在Search Insert Position的Java提交中击败了96.32% 的用户

内存消耗 : 37.3 MB, 在Search Insert Position的Java提交中击败了90.39% 的用户

```java
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums==null||nums.length==0) return 0;
        int low = 0;
        if(nums[low]==target) return low;
        int high = nums.length - 1;
        if(nums[high]==target) return high;
        int mid = (high+low)/2;
        while(low<=high){
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                low = mid+1;
                mid = (high+low)/2;
            }
            else{
                high = mid-1;
                mid = (high+low)/2;
            }
        }
        return low;
        
    }
}
```

其实套用类库Arrays里面的binarySearch()更加简单,binarySearch在失配时就是返回（- 插入点索引 - 1）。所以很容易倒推出插入点。只是这样做就失去了这道题目的意义（当然，掌握一下类库的使用还是好的~）：

执行用时 : 1 ms, 在Search Insert Position的Java提交中击败了96.32% 的用户

内存消耗 : 37.9 MB, 在Search Insert Position的Java提交中击败了81.23% 的用户
```java
class Solution{
	public int searchInsert(int[] nums, int target) {
        int res = Arrays.binarySearch(nums,target);
        if(res>=0)return res;
        else return -res-1;

    }
}
```