若当前指针cur不为0，则交换nums[cur]与nums[pre],pre++
``` C++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pre=0,cur=0;
        while(cur<nums.size())
        {
            if(nums[cur]!=0)
            {
                int temp=nums[cur];
                nums[cur]=nums[pre];
                nums[pre]=temp;
                pre++;
            }
            cur++;
        }
    }
};