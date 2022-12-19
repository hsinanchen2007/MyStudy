感觉出题有BUG吧，nums[1]+...+nums[max]==0时，不管nums[0]为何值，索引都是0，按照题目描述的要求，就不应该存在索引是0的情况，所以只能按照官方题解选择暴力法硬凑。
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum(0),leftsum(0);
        for (int i=0;i<nums.size();i++)
            sum+=nums[i];
        for (int i=0;i<nums.size();i++){
            if (2*leftsum==sum-nums[i])
                return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};
