```
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i,j,k,flag=0;
        vector<int> ans;
        for(i=0;i<nums.size();i++){
            int temp =nums[i];
            int pos = i;
            for(j=i;j<nums.size();j++){
                if(nums[j]>temp) {
                flag=1;
                ans.push_back(nums[j]);
                break;
                }
            }if(flag==0){
            for(k=0;k<pos;k++){
                if(nums[k]>temp) {
                ans.push_back(nums[k]);
                flag=1;
                break;
                }
            }
            }
           if(k==pos&&flag==0){
               ans.push_back(-1);
           }else{
               flag=0;
           }
         
        }
        return ans;
        
    }
};
```
