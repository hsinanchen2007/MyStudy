### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() == 0)return false;
        sort(nums.begin(), nums.end());  //排序
        int zeros=0;  //大小王的数量
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(nums[i] == 0)
            {
                ++zeros;
                continue;
            }
            if(nums[i] == nums[i+1])  //重复了
            {
                return false;
            }
            zeros = zeros - (nums[i+1]-nums[i]-1);  //表示nums[i+1]和nums[i]之间需要多少大小王来填充
        }
        return zeros >= 0;
    }
};
```