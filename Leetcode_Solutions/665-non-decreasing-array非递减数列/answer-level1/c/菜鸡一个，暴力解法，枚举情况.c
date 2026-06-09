bool checkPossibility(int* nums, int numsSize){
    int cnt=0;
     for(int i=0;i<numsSize-1;i++)
     {
         if(nums[i]>nums[i+1]&&i==0){
             for(int i=1;i<numsSize-1;i++)
             {
                 if(nums[i]>nums[i+1]) return 0;
             }
             cnt++;
         }
         else if(nums[i]>nums[i+1]&&i>0&&i<numsSize-2){
             if(nums[i+1]>nums[i+2]) return 0;
            else if(nums[i+1]<=nums[i+2]&&nums[i+1]>=nums[i-1]) cnt++;
             else if(nums[i+1]<=nums[i+2]&&nums[i+2]>=nums[i]) cnt++;
             else if(nums[i+1]<=nums[i+2]&&nums[i+2]<nums[i]) return 0;
         }
          else if(nums[i]>nums[i+1]&&i==numsSize-2){
             cnt++;
         }
         if(cnt>1) return 0;
     }
     return 1;
}