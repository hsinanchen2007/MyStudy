### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return a < b;
        });
        return nums;
    }
};
```