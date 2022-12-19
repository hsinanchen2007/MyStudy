```
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
          if(k<=1) return 0;
          int l=0,sum=0,res=1;
          for(int r=0;r<nums.size();r++){
              res *= nums[r];
              while(res>=k){
                res/=nums[l];
                l++;
              }
            sum +=r-l+1;
          }
         return sum;
    }
};
```
