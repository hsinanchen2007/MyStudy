`遍历nums,nums[nums[i]]如果大于0，则赋值为其相反数，如果已经小于等于0，则赋值为0，遍历完成后，再次遍历，如果nums[i]==0，返回其下标即为结果`
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int idx = abs(nums[i]);
            nums[idx] = (nums[idx] > 0) ? -nums[idx]: 0;
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
                return i;
        }
        return 0;
    }
};
```
