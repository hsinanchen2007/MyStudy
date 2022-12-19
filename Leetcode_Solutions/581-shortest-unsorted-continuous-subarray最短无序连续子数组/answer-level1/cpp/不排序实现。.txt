
- 每次从左往右判断i(下标)位置是否比前i个的最大值大，如果是则说明位置在这i + 1中正确,假设不是，则说明
位置不对，因为从小到大，i位置应该这i + 1中最大才符合要求。不对记录下右边界索引，如果后面都是比i位置大
正确排序则i就是最右的索引了。
- 从右往左同理。

```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int m = nums[0], n = nums.back(), l = -1, r = -2;
        int len = nums.size();
        for (int i = 1; i < len; ++i)
        {
            m = max(m, nums[i]);
            n = min(n, nums[len - 1 - i]);
            if (m != nums[i]) r = i;
            if (n != nums[len - 1 - i]) l = len - 1 - i;
        }
        return r - l + 1;
    }
};
```