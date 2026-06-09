```
//没有使用队列，先找出前k个元素的最大值，然后滑动找剩下的
//进入一个元素，判断最大值是否是左边界值，如果是就得重新找最大值
//如果不是 判断最大值是否小于新进来的值，小于更换，不小于不更换
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())    return {};
        vector<int> ans;
        int Max = nums[0];
        for(int j = 1; j<k;j++) {
            Max = max(nums[j], Max);
        }
        ans.push_back(Max);
        for(int i = k; i<nums.size(); i++) {
            if(nums[i-k] == Max) {
                //如果最大值在左边界，需要从中找出最大值
                Max = nums[i];
                for(int j = i-k+1;j<i; j++) {
                    Max = max(Max, nums[j]);
                }
            }
            //如果不在边界，判断最大值如当前跟新的值 如果更新值大于最大值，则改变最大值
            else if(Max < nums[i] ) {
                Max  = nums[i];
            }
            ans.push_back(Max);
        }
        return ans;
    }
```