### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *std::min_element(std::begin(nums), std::end(nums));

    }
};
```