### 解题思路
设置一个数组，二次循环；
一旦遇到比当前值小的数据，则对c加一，最后加入数组。

### 代码
``` cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count;
        int c;
        for(size_t i=0;i<nums.size();++i)
        {
            c=0;
            for(size_t j=0;j<nums.size();++j)
            {
                if(nums[i]>nums[j])
                    ++c;
            }
            count.push_back(c);
        }
        return count;
    }
};
```