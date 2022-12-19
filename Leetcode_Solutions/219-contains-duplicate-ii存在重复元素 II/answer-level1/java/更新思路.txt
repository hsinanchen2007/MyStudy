```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        if(k == 0) return false;
        if(n <= 0) return false;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<n;i++){
            if(map.get(nums[i]) != null && (i - map.get(nums[i])) <= k) return true;
            //map的值会更新，如果说满足不为null的话，判断索引的绝对值差如果说不满足这个条件，更map相同值的键值对。
            map.put(nums[i], i);
        }
        return false;
    }
}
```
走一遍代码就可以了解到这一种思路，其实是不断的更新相同值的位置。键是数组元素，值是数组索引。
不断的更新理的最大绝对值差的两个数，如果存在就返回true。