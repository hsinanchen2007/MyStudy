### 解题思路
先使用二分法，找到target的一个大概位置。

找到中心后，然后由中心向两边扩展，探索两个边界的索引。

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0 ; 
        int right = nums.length-1;
        int[] ans = {-1,-1};
        if(nums == null || nums.length == 0 ||nums[left] > target || nums[right] < target) return ans;
        boolean findTarget = false;

        int mid = 0;//遇到target的位置
        //二分法查找target的大概位置
        while(left <= right){
            mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid +1;
            }else if(nums[mid] > target){
                right = mid -1;
            }else{
                findTarget = true;//探索到了target的位置
                break;
            }
        }

        if(!findTarget) return ans;//没有找到target

        //搜索第一个索引
        int first = mid;
        while(first >= 0){
            if(nums[first] == target){
                first--;
                continue;
            }
            break;
        }
        ans[0] = first+1;

        //搜索最后一个索引
        int last = mid;
        while(last < nums.length){
            if(nums[last] == target){
                last++;
                continue;
            }
            break;
        }
        ans[1] = last-1;

        return ans;
    }
}
```