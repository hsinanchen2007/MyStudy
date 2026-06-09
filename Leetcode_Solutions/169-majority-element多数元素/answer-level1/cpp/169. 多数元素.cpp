### 解题思路
 因为多数元素大于n/2,所以将多数元素和与它不同的元素相抵消，最终一定是多数元素剩余
 于是遍历数组，pre为当前最多的元素，如果遇到不同于pre则cnt--
 相同则cnt++,当cnt为0时，在选择一个元素作为当前最多的元素，

### 代码

```cpp
class Solution {
public:

    int majorityElement(vector<int>& nums) {
        int pre = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0)
                pre = nums[i];
            if (nums[i] == pre)
                cnt++;
            else
                cnt--;
        }
        return pre;
    }
};
```