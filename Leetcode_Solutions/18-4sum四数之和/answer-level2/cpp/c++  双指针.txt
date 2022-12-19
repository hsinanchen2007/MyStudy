

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(),nums.end());
        for(int a = 0; a <= n-4;a++) //这里的有等号
        {
            if(a > 0 && nums[a] == nums[a-1]) continue; //排除重复元素
            for(int b = a+1; b <= n-3; b++)
            {
                if(b > a+1 && nums[b] == nums[b-1]) continue; //排除重复元素
                int c = b+1, d = n-1;
                while(c < d)
                {
                    if(nums[a]+nums[b]+nums[c]+nums[d] < target)
                    {
                        c++;
                    }
                    else if(nums[a]+nums[b]+nums[c]+nums[d] > target)
                    {
                        d--;
                    }
                    else
                    {
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while(c < d && nums[c] == nums[c+1])
                        {
                            c++;
                        }
                        while(c < d && nums[d] == nums[d-1])
                        {
                            d--;
                        }
                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};
```