```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,k=0;
        for(int m=0;m<n;m++){
            if(nums[m]==0)
                i++;
            else if(nums[m]==1)
                j++;
            else if(nums[m]==2)
                k++;
        }
        int m=0;
        while(i>0){
            nums[m++]=0;
            i--;
        }
        while(j>0){
            nums[m++]=1;
            j--;
        }
        while(k>0){
            nums[m++]=2;
            k--;
        }
        
    }
};
```
