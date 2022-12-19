```
    int findPeakElement(vector<int>& nums) {
        
        if(nums.size()<=1) return 0;
        
        int i=0, j=nums.size()-1;
        while(i<=j){
            int mid = (j-i)/2+i;
            if(mid-1>=0){
                if(nums[mid-1]>nums[mid]){
                    j = mid-1;
                }else{
                    if(mid==nums.size()-1 || nums[mid]>nums[mid+1]) return mid;
                    i = mid+1;
                }
            }else if(mid+1<nums.size()){
                if(nums[mid]>nums[mid+1]){
                    if(mid==0 || nums[mid]>nums[mid-1]) return mid;
                    j = mid-1;
                }else{
                    i = mid+1;
                }
            }else{
                cout<<"Error";
            }
        }
        return 0;
    }
```