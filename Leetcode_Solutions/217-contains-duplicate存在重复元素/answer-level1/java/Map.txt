class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            //如果Map里面没有该元素，就往里面加
            if(map.get(nums[i])==null){
                map.put(nums[i],i);
            //如果Map里面存在该元素了，就直接返回
            }else if(map.get(nums[i])!=null){
                return true;
            }
        }
        return false;
    }
}