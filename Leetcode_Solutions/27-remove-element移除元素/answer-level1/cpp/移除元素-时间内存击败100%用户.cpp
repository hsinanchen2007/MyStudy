![image.png](https://pic.leetcode-cn.com/91fe745f39d8731a2a91351cc39088be5742e9070aacf03202498da67fa1d98e-image.png)
### 解题思路
1. 定位到第一次出现`val`的位置，赋值给`i`。
2. 从`j=i+1`位置出发出一次遍历整个数组，当`nums[j]!=val`时将该位置数值移动到`i`位置，并做`i++`；当`nums[j]==val`时则跳过该位置的数。
3. 此时`i`是位于新数组的后面一位，所以i就是新数组的长度，返回即可。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // if(nums.size() < 2)
        unsigned i;
        for(i=0;i<nums.size();i++)
            if(nums[i] == val) break; // 定位到第一个val的位置
        for(unsigned j=i+1;j<nums.size();j++)
        {
            if(nums[j] == val) continue;
            nums[i] = nums[j];
            i++;
        }
        return i;
    }
};
```