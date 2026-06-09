### 解题思路
利用 max_element 找到最大值的下标然后在进循环判断是否大于其他元素的两倍。
### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxPosition = max_element(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[maxPosition] < nums[i] * 2 && nums[maxPosition] != nums[i])
                return -1;
        }
        return maxPosition;
    }
};
```