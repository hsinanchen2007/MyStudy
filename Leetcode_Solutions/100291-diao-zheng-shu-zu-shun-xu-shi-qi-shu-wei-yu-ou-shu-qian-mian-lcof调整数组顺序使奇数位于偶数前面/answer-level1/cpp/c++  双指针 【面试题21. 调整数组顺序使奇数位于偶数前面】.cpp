### 解题思路
j保存当前待交换的位置， i向后滑动寻找奇数，找到后交换nums[i]和nums[j]
每次交换后j向后滑动1，[j,i)之间绝对不会出现奇数
### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) swap(nums[i], nums[j++]);
        }
        return nums;
    }
};
```