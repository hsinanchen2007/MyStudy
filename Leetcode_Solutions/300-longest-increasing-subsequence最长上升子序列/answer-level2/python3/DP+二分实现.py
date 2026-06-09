### 解题思路
具体的解题思路不展开阐释，就是使用了动态规划+二分查找的基本方法。
二分查找使用了cpp的std::lower_bound()和python3的bisect.bisect_left，方便又好用。

### 代码
```cpp []
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1)
            return nums.size();

        vector<int> res{nums[0]};
        for (auto i = nums.begin()+1; i != nums.end(); i++) {
            auto idx = lower_bound(res.begin(), res.end(), *i);
            if (idx == res.end())
                res.push_back(*i);
            else *idx = *i;
        }
        return res.size();
    }
};
```
```python3 []
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 1 or len(nums) == 0: 
            return len(nums)
        tails = [nums[0]]
        for i in nums[1:]:
            idx = bisect.bisect_left(tails, i)
            if idx == len(tails):
                tails.append(i)
            else:
                tails[idx] = i
        return len(tails)
```

