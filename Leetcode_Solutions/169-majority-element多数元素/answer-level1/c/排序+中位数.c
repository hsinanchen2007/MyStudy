### 解题思路
可以将数组先排序，然后出现次数超过一半的必定在数组中间位置。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums.at(nums.size()/2);
    }
};
```