### 解题思路
![图片.png](https://pic.leetcode-cn.com/c4a409ef83f0bd408cca8fb7474ffae257a1b042595bcb9606b3889cce862112-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int pos1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int pos2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return (pos2 - pos1 > nums.size() / 2);
    }
};
```