### 解题思路
排序返回第k个元素即可

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];

    }
};
```