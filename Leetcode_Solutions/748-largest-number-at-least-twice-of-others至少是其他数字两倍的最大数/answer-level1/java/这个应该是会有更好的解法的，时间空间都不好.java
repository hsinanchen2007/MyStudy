```
class Solution {
    //应该还是会有更好的解法的。
    public int dominantIndex(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>() ;
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],i) ;
        }
        if(nums.length<=1){
            return 0 ;
        }
        Arrays.sort(nums) ;
        if(nums[nums.length-1]>=nums[nums.length-2]*2){
            return map.get(nums[nums.length-1]) ;
        }
        return -1 ;
    }
}
```
