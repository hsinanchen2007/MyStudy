### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left=0,right=0;
        while(right<nums.size())
        {
            if(right<nums.size()-1&&nums[right+1]-1<=nums[right])
                ++right;
            else
            {
                if(left==right)
                {
                    string tmp=to_string(nums[left]);
                    res.push_back(tmp);
                    ++right;
                    ++left;
                }
                else
                {
                    string tmp=to_string(nums[left])+"->"+to_string(nums[right]);
                    res.push_back(tmp);
                    ++right;
                    left=right;
                }
            }
        }
        return res;
    }
};
```