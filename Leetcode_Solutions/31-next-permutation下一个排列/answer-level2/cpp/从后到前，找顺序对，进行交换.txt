```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(j=nums.size()-2; j>=0; j--)
        {
            for(i=nums.size()-1; i>j; i--)
            {
                if(nums[i]>nums[j])
                {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin()+j+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};
```

优化
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(j=nums.size()-2; j>=0; j--)
        {
            if(nums[j]>=nums[j+1])
                continue;
            for(i=nums.size()-1; i>j; i--)
            {
                if(nums[i]>nums[j])
                {
                    swap(nums[i], nums[j]);
                    reverse(nums.begin()+j+1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};
```

