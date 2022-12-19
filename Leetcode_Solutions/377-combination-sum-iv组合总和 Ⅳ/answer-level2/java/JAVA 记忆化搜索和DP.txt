```
class Solution {
    
    HashMap<Integer,Integer> cache=new HashMap<>();

    public int combinationSum4(int[] nums, int target) {
        if(cache.containsKey(target))
            return cache.get(target);
        if(target==0)
            return 1;
        int res=0;
        
        for(int i=0;i<nums.length;i++){
            if(target-nums[i]>=0){
                res+=combinationSum4(nums,target-nums[i]);
            }
        }
        
        cache.put(target,res);
        return res;


    }
}
```
```
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int []dp=new int[target+1];
        dp[0]=1;

        for(int sum=1;sum<=target;sum++){
            for(int num:nums){
                if(sum>=num)
                    dp[sum]+=dp[sum-num];
            }
        }
        return dp[target];

    }
}
```
