```
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size()%2 != 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=1;i<nums.size();i+=2){
            sum += min(nums[i-1],nums[i]);
        }
        return sum;
    }
};
```
