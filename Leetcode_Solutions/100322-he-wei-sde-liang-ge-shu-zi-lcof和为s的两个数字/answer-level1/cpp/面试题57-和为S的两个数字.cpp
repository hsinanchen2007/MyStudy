### 解题思路
利用排序数组的特性，前后双指针。
如果和大了，就后指针前移；小了则前指针后移。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.empty())
            return res;
        int front = 0;
        int back = nums.size()-1;
        while(front < back)
        {
            int tmp = nums[front]+nums[back];
            if(tmp == target)
            {
                res.push_back(nums[front]);
                res.push_back(nums[back]);
                return res;
            }
            else if(tmp > target)
            {
                back -= 1;
            }
            else
            {
                front += 1;
            }
        }
        return res;
    }
};
```