### 解题思路


### 代码

```cpp
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        if(nums.size() == 2)
            return abs(nums[0] - nums[1]) + 1;
        int cnt1 = 0, cnt2 = 0;
        vector<int> nums1, nums2;
        nums1 = nums;
        nums2 = nums;
        if(nums1[0] <= nums1[1])
        {
            cnt1 += nums1[1] - nums[0] + 1;
            nums1[1] -= (nums1[1] - nums1[0] + 1);
        }
        for(int i = 2 ; i < nums1.size() - 1 ; i += 2)
        {
            if(nums1[i] <= nums1[i - 1])
            {
                cnt1 += nums1[i - 1] - nums1[i] + 1;
                nums1[i - 1] -= (nums1[i - 1] - nums1[i] + 1);
            }
            if(nums1[i] <= nums1[i + 1])
            {
                cnt1 += nums1[i + 1] - nums1[i] + 1;
                nums1[i + 1] -= (nums1[i + 1] - nums1[i] + 1);
            }
        }
        if(nums1.size() % 2)
        {
            if(nums1.back() <= nums1[nums1.size() - 2])
            {
                cnt1 += nums1[nums1.size() - 2] - nums.back() + 1;
                nums1.back() -= (nums1[nums1.size() - 2] - nums.back() + 1);
            }
        }
        if(nums2[0] >= nums2[1])
        {
            cnt2 += nums2[0] - nums2[1] + 1;
            nums2[0] -= (nums2[0] - nums2[1] + 1);
        }
        for(int i = 1 ; i < nums2.size() - 1 ; i += 2)
        {
            if(nums2[i] <= nums2[i - 1])
            {
                cnt2 += nums2[i - 1] - nums2[i] + 1;
                nums2[i - 1] -= (nums2[i - 1] - nums2[i] + 1);
            }
            if(nums2[i] <= nums2[i + 1])
            {
                cnt2 += nums2[i + 1] - nums2[i] + 1;
                nums2[i + 1] -= (nums2[i + 1] - nums2[i] + 1);
            }
        }
        if(nums2.size() % 2 == 0)
        {
            if(nums2.back() <= nums2[nums2.size() - 2])
            {
                cnt2 += nums2[nums2.size() - 2] - nums.back() + 1;
                nums2.back() -= (nums2[nums2.size() - 2] - nums.back() + 1);
            }
        }
        cout<<cnt1<<" "<<cnt2<<endl;
        return min(cnt1, cnt2);
    }
};
```