想法就是官方题解的想法，我想解释一下如何才能想到这个方法。
要求包含`a_i`的滑动窗口的最大值，也就是求窗口内`a_i`右侧的最大值和左侧的最大值两者之间的最大值，`a_i`右侧的最大值用`left`数组存储，`a_i`左侧的最大值用`right`数组存储。大致就是这样。
```
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0) return vector<int> (0);
        vector<int> left(len), right(len);
        for(int i=0; i<len; i++){
            if (i % k == 0)
                left[i] = nums[i];
            else
                left[i] = max(left[i-1], nums[i]);
            if (i == 0 || (i-len%k)%k == 0)
                right[len-i-1] = nums[len-i-1];
            else
                right[len-i-1] = max(right[len-i], nums[len-i-1]);
        }
        vector<int> ans(len-k+1);
        for(int i=0; i<len-k+1; i++)
            ans[i] = max(right[i], left[i+k-1]);
        return ans;
    }
};
```
