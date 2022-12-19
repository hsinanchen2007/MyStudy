### 解题思路
首先我们定一个目标index，一开始这个目标是数组最后一个元素的位置。
然后我们往前遍历数组，当遍历到某个元素的值大于这个元素的位置和index之间的距离，那么就将index转换为这个元素的位置。
这个是目标转换的思想，表明只要能到达这个元素，那么就能到达index元素
一直迭代，当index为0，表明以0为起点能够到达最后的目标

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
            if(nums[i]>=index-i) index=i;
        return index==0?true:false;
    }
    
};
```