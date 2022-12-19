### 解题思路
《编程之美》上有这道题目。
如果存在一个数x在数组中出现次数大于⌊ n/2 ⌋ 次，假定其与其他数字一一抵消后，最终剩下的数字肯定为x。
如果两个非x的不同数字一一抵消，不会对最终结果产生影响。
因此我们的想法就是遍历一遍数组，把不一样的数字一一抵消，最终剩下的数字就是x。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0], cnt = 1;
        for(int i=1;i<nums.size();++i) {
            if (cnt == 0) {
                x = nums[i];
                ++cnt;
                continue;
            }
            if (x == nums[i]) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return x;
    }
};
```