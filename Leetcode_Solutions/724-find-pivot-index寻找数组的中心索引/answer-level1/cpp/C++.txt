```
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int sum =0;
        for(int num :nums){
            sum += num;
        }
        int subSum = 0;
        for(int i = 0;i<nums.size();i++){
            if(subSum*2 == (sum-nums[i]))
                return i;
            else
                subSum += nums[i];
        }
        return -1;
    }
};
```
