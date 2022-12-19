### 解题思路
1、标记为负号
2、数组统计次数(也可以用map)
3、排序 比较相邻元素


### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            int& num = nums.at(abs(nums.at(i)));
            if(num < 0)
                return abs(nums.at(i));
            num *= -1;
        }
        return 0;
    }

    int findRepeatNumber(vector<int>& nums)
    {
        vector<int> v(nums.size());

        for(int i = 0; i < nums.size(); ++i)
        {
            ++v.at(nums.at(i));
            if(v.at(nums.at(i)) >= 2)
            {
                return nums.at(i);
            }
        }

        return 0;
    }

    int findRepeatNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < (int)nums.size() - 1; ++i)
        {
            if(nums.at(i + 1) == nums.at(i))
                return nums.at(i);
        }
        
        return 0;
    }

};
```