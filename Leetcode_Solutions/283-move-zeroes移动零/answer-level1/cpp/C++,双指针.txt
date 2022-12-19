```
class Solution {
public:
//双指针
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[j++]=nums[i];
            }
        }
        for(int k=j;k<n;k++)nums[k]=0;
    }
};
```
