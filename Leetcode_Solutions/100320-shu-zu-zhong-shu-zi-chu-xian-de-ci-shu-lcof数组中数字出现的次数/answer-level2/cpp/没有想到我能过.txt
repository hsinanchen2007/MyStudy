### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        /* bit ａ若只求一个那就是位运算, 但现在要求两个, 我们可以得到这两个数字xor的结果
        一种想法是把这两者结合起来*/
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        sort(nums.begin(), nums.end());
        int a = nums[0];
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i+1]) {
                a = nums[i];
                break;
            }
        }
        return {a, res ^ a};
        // return res;
        /*
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res ^= n;
            
        }*/
    }
};
```