```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N=nums.size(),j=1;
        vector<int> temp(N+1,0);

        for(int i=0;i<N;i++){
            if(nums[i]>0&&nums[i]<N+1){
                temp[nums[i]]=1;
            }
        }
        
        for(;j<N+1;j++){
            if(temp[j]!=1){
                return j;
            }
        }
        return j;
    }
};
```
