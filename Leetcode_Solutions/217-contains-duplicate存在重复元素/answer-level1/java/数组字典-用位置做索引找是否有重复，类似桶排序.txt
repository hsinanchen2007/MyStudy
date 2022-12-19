class Solution {
    public boolean containsDuplicate(int[] nums) {
          if(nums.length==0){
            return false;
        }
        int min=nums[0];
        int max=nums[0];
        for(int i=0;i<nums.length;i++){
            max=max>nums[i]?max:nums[i];
            min=min<nums[i]?min:nums[i];
        }
        
        int[] map=new int[max-min+1];
        
       Arrays.fill(map,-1);
        
        int len=0;
        for(int i=0;i<nums.length;i++){
            if(map[nums[i]-min]==-1){
                map[nums[i]-min]=i;
            }else{
                return true;
            }
        }
        return false;
    }
}