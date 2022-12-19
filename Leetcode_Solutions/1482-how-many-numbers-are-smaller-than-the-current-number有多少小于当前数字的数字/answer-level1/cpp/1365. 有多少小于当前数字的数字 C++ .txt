### 解题思路
排序

### 代码

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> nums_copy(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        int n = 0;
        vector<int> v(128); // v的下标为nums中的数
        v.at(nums.at(n)) = n;

        //统计每个数 小于它的数
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(nums.at(i + 1) != nums.at(i))
            {
                n = i + 1;
            }
            v.at(nums.at(n)) = n;
        }

        vector<int> res;
        res.reserve(nums.size());
        for(int i = 0; i < nums_copy.size(); ++i)
        {
            res.push_back(v.at(nums_copy.at(i)));
        }

        return res;
    }
};