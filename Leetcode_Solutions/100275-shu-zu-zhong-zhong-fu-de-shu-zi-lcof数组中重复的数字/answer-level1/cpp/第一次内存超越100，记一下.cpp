### 解题思路
此处撰写解题思路

### 代码
![dde87fb050fd80f8909ba46f6992ac1.png](https://pic.leetcode-cn.com/33d7451748fd3ecdf69eb44c98a7d847ce42f9ea48e540af6bddf4dff2d120cc-dde87fb050fd80f8909ba46f6992ac1.png)

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> uo_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(uo_map.find(nums[i]) != uo_map.end())
                return nums[i];
            else
                uo_map.insert(nums[i]);
        }
        return 0;
    }
};
```