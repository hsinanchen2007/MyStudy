```
class Solution {
    // 这种hash表的方式思路简单。没啥说的。
    //但是这种问题应该是可以试用异或的思路来做的吧。
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>() ;
        for(int i=0;i<nums.length;i++){
            if(set.contains(nums[i])){
                return true ;
            }
            set.add(nums[i]) ;
        }
        return false ;
    }
}
```
