### 解题思路
这题其实可以直接用c++自带的unique函数，只要一行代码

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(),nums.end())-nums.begin();
    }
};
```