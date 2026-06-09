### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        vector<int> temp;
        temp.push_back(1);
        for (int i=1; i<nums.size(); i++)
            temp.push_back(0);

        int maxans = 1;
        for (int i=1; i<nums.size(); i++)
        {
            int max_ = 0;
            for (int j=0; j<i; j++)
                if (nums[i] > nums[j])
                    max_ = max(max_, temp[j]);

            temp[i] = max_ + 1;
            maxans = max(maxans, temp[i]);
        }

        return maxans;
    }
};
```