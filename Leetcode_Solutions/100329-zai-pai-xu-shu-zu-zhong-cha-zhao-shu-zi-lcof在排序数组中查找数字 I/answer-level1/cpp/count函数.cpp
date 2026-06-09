### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a;
        a=count(nums.begin(),nums.end(),target);
        return a;
    }
};
```