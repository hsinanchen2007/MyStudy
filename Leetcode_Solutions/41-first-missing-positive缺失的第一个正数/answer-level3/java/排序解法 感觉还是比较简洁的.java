 
public int firstMissingPositive(int[] nums) {
        int ans=1;
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
              if(nums[i]<=0){
                  continue;
              }
              if(i<nums.length-1&&nums[i]==nums[i+1]){
                  continue;
              }
              if(ans==nums[i]){
                  ans++;
              }
        }
        return ans;
 }