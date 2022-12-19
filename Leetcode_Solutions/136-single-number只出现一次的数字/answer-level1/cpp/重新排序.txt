```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<N-1;i++){
            if(nums[i]!=nums[i+1])
                return nums[i];
            else
                i++;
        }
        return nums[N-1];
    }
};
```
