```
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer,Integer>map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            //每一次进行比较，后位减前位置
            if(!map.containsKey(nums[i])){
                //如果没有，扔进去
                map.put(nums[i],i);
            }else{
                int past = map.get(nums[i]);
                if(i-past<=k)return true;
                map.put(nums[i],i);
            }
        }
        return false;
    }
}
```
