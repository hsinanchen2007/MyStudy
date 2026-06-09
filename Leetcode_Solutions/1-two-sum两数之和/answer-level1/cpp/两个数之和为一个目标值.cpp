### 解题思路
此处撰写解题思路
挺简单的，遍历就可以了
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vecTwo;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target == (nums[i] + nums[j]))
                {
                    vecTwo.push_back(i);
                    vecTwo.push_back(j);
                }
            }
        }
        return vecTwo;
    }
};
```