```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m,lm,rm;
        while(l<=r)
        {
            m = (l+r)/2;
            if(nums[m] > target)
            {
                r = m-1;
            }
            else if(nums[m] < target)
            {
                l = m+1;
            }
            else
            {
                lm = m;
                rm = m;
                while(l<lm && nums[l]!=target)
                {
                    m = (l+lm)/2;
                    if(nums[m]<target)
                        l = m+1;
                    else
                        lm = m;
                }
                while(rm<r && nums[r]!=target)
                {
                    m = (rm+r+1)/2;
                    if(nums[m]>target)
                        r = m-1;
                    else
                        rm = m;
                }
                return {l, r};
            }

        }
        return {-1, -1};
    }
};
```
优化，先找左边界，再找右边界
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m,l2;
        if(nums.empty())
            return {-1, -1};
        while(l<r)
        {
            m = (l+r)/2;
            if(nums[m] >= target)
                r = m;
            else
                l = m+1;
        }
        if(nums[l] != target)
            return {-1, -1};
        l2 = l;
        r = nums.size()-1;    
        while(l2<r)
        {
            m = (l2+r+1)/2;
            if(nums[m]<=target)
                l2 = m;
            else
                r = m-1;
        }
        return {l, r};
    }
};
```
