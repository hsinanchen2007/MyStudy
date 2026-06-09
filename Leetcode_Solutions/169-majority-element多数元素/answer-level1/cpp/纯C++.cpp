### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;

        int majority = 0;
        int sum = 0;

        for (auto index : nums)
        {
            counts[index]++;

            if (sum < counts[index])
            {
                majority = index;
                sum = counts[index];
            }
        }

        return majority;
    }
};
```