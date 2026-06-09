dp
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i - 1] + nums[i], nums[i]);
            maxsum = max(maxsum, nums[i]);
        }
        return maxsum;
    }
};
```
归并的方式
```
class Solution {
    vector<int> nums;
    int dac(int left, int right)
    {
        if(left == right)
            return nums[left];

        int mid = (left + right)>>1;
        int leftval = dac(left, mid);
        int righval = dac(mid + 1, right);

        int crossleft = -1000000, crossright = -1000000;
        int cur = 0;
        for(int i = mid; i >= left; i--)
        {
            cur += nums[i];
            crossleft = max(crossleft, cur);
        }
        cur = 0;
        for(int i = mid + 1; i <= right; i++)
        {
            cur += nums[i];
            crossright = max(crossright, cur);
        }
        int crossmax = crossleft + crossright;
        return max(max(leftval, righval), crossmax);
    }
public:
    int maxSubArray(vector<int>& _nums) {
        nums = _nums;
        return dac(0, nums.size() - 1);
    }
};
```
