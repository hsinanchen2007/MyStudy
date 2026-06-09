### 解题思路
因为数组里的数字都在0~n-1的范围内，因此我们令每个数字到它对应的下标，如nums[1] = 1这样。最后如果得到nums[i] == nums[nums[i]]即出现重复值，返回即可。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            while(i != nums[i]) {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return 0;
    }
};
```