二分查找
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int temp=0;
        reverse(nums.begin(),nums.end());
        int max=nums[0];
        int min=1;
        int mid=(max+min)/2;
        while(1){      
             int sum=nums.size();
             int sum1=nums.size(); 
             if (mid==1) return 1;
            for(int j=0;j<nums.size();j++){
                sum+=(nums[j]-1)/mid; 
                sum1+=(nums[j]-1)/(mid-1);
            }
            if(sum<=threshold&&sum1>threshold)
               return mid;
            else if(sum>threshold){
                min=mid;
                mid=(max+min)/2;

            }else if (sum1<=threshold){
                max=mid;
                mid=(max+min)/2;
            }
                
            }
        
    }

    
};