### 解题思路
思路简单，但是问题在于对可能是最后一个不存在的元素的判断。
这种情况下，如果还要使用遍历方式去获取，会发生越界的情况，可以使用条件`i == nums.size() - 1`提前终止循环。

![image.png](https://pic.leetcode-cn.com/bfae404f35230addcd860c83f53e6aaae41dc139c2be55c02960a662c447d3df-image.png)


### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        for(int i = 0; i <= nums.size(); i++) {
            if(i != nums[i]) {
                return i;
            }

            if(i == nums.size() - 1){
                return i + 1;
            }
        }
        return 1;
    }
};
```