class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j;
        vector<int> result;
        if(nums.size()==0)
            return result;
        for(int j=0; j<k; ++j){
            if(nums[j]>nums[i])
                i = j;
        }
        result.push_back(nums[i]);
        for(int j=k; j<nums.size(); ++j){
            if(nums[j]>=nums[i])
                i = j;          // 如果新来的最大值比原来的大，那么新来的一定是当前窗口的最大值
            else if(j-i>=k){   // 如果旧的最大值不在滑动窗口内
                int val = nums[i+1];
                i=i+1;
                for(int t=i+1; t<=j; ++t)
                    if(nums[t]>=val){
                        i = t;
                        val = nums[t];
                    }
            }
            result.push_back(nums[i]);
        }
        return result;
    }
};