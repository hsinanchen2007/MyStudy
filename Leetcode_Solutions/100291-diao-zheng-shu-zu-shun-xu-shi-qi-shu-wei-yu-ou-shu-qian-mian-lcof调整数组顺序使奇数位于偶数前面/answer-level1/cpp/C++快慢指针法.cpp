定义一个快指针fast和慢指针low
low用来记录偶数的位置
fast向后遍历，遇到奇数的时候交换low和fast

判断奇数用 （num&1）==1 这个方法。

```
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low=0;
        int fast=0;
        while(fast<nums.size())
        {
            if((nums[fast]&1)==1)
            {
                swap(nums[low],nums[fast]);
                low++;
            }
            fast++;
        }
        return nums;

    }
};
```
