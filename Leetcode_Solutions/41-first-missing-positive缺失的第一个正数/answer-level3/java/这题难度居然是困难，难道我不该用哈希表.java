class Solution {
    public int firstMissingPositive(int[] nums) {
        int m=nums.length;
        
        Arrays.sort(nums);
        
        Map<Integer,Integer> map=new HashMap<>();
        
        if(m==0||nums==null||nums[m-1]<=0){
            return 1;
        }
        for(int i=0;i<m;i++){
            map.put(nums[i],1);
        }
        
        for(int i=1;i>0;i++){
            if(map.containsKey(i)){
                continue;
            }
            else{
                return i;
            }
        }
        return  -1;
    }
}