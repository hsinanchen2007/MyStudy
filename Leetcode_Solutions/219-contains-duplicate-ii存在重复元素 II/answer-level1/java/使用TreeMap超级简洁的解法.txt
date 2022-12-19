```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        TreeMap<Integer,Integer> map=new TreeMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i])){
                if(i-map.get(nums[i])<=k)return true;
            }
            map.put(nums[i],i);
        }
        return false;
    }
}
```
