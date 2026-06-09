![leetcode.jpg](https://pic.leetcode-cn.com/e4027084ad82d1c3ae1e05ab1ab5b4ff2d23bbf5404833091aa8e76fc9990f64-leetcode.jpg)


### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) 
            if(last - i <= nums[i]) last = i;
        return last == 0;
    }
};
```