- 只要找到旋转前后对应的index关系，做一个转换，就是一个基本的二分查找题。
- 先用二分法找到最小值，即pivot，便能找到对应关系：实际（经过旋转的）index = （（无旋转，从小到大排序的）index + pivot）% nums.length

```
class Solution {
    private int pivot;
    private int size;
    public int search(int[] nums, int target) {
        if(nums == null || nums.length == 0)    return -1;
        //use binary search to find the pivot point first
        size = nums.length;
        int l = 0;
        int r = size-1;
        while(l < r-1){
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[l] && nums[mid] > nums[r]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        pivot = nums[l] < nums[r] ? l : r;
        //now find the target by shifting the index;
        //actualIndex = (virtualIndex + pivotIndex)%nums.length
        l = 0;
        r = size-1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[convertIndex(mid)] == target){
                return convertIndex(mid);
            }
            else if(nums[convertIndex(mid)] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
    private int convertIndex(int index){
        return (index + pivot)%size;
    }
}
```
