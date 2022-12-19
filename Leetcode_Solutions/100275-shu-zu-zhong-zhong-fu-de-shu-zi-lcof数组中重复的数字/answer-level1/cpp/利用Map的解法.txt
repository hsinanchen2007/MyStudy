### 解题思路
这个题目比较简单

遍历数组将值作为key存入map中，在循环过程中判断key是否存在，如果存在，那么此值为重复

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> numberMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (numberMap.find(nums[i]) != numberMap.end()) {
                // find it
                return nums[i];
            }
            numberMap[nums[i]] = 1;
        }
        return 0;
    }
};
```