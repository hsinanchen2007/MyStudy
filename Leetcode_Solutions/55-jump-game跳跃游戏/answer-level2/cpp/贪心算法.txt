### 解题思路
从最末端开始，只要能够到达lastpos位置的就更新，逐步往前推。
这道题讨巧的地方在于，数组中的步数不是确定的，小于等于该步数都可以，所以贪心算法是成立的。

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()==0 || nums.size()==1) return true;
        int pos = nums.size()-1;
        int lastpos = nums.size()-1;
        while (pos >= 0) {
            if (nums[pos] + pos >= lastpos)
                lastpos = pos;
            pos--;
        }
        if (lastpos == 0) return true;
        else return false;
    }
};
```