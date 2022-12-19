使用平衡二叉搜索树来作为滑动窗口元素的容器。
```
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> set = new TreeSet<>();
        for(int i=0;i<nums.length;i++){
            
            Integer s = set.ceiling(nums[i]);
            if(s != null && s <= nums[i]+t)
                return true;
            
            Integer g = set.floor(nums[i]);
            if(g != null && nums[i] <= g+t)
                return true;
            
            set.add(nums[i]);
            if(set.size() > k)
                set.remove(nums[i-k]);
        }
        return false;
    }
}
```
