```
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        if(nums.length != map.size()){
            return true;
        }
        return false;
    }
}
```
将数组元素作为K键，对应下标作为V值存入哈希表，当数组中存在重复的元素的时候，存入哈希表的时候会出现丢键的情况，因为哈希表的K值是不允许重复的。
所以说，将数据元素存入哈希表后吗，比较两者的长度，如果长度一致，表示没有重复元素，返回false，如果长度不一致，代表存在重复元素，返回true值
