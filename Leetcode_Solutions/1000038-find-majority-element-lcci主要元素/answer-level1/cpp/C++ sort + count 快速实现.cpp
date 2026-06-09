### 思路
就是在查询数列中`值同中位数相等的数`能否占据全体数组的一半。
中位数：通过`sort`的结果得到，`count(*.begin, *.end， value)`实现对中位数占据总数比重的计数。
### 代码
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int cmp = nums[len / 2];
        if(count(nums.begin(), nums.end(), cmp) > len / 2) {
            return cmp;
        }
        return -1;
    }
};
```
