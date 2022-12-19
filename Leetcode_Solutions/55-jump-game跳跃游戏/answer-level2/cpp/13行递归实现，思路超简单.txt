### 解题思路
从后开始往前遍历
最后的位置是location=lens-1
nums[location-1]>=1  nums[location-2]>=2 以此类推只要其中满足一项即可
 假如第i个满足,将第i位作为最后一位,location = i.
 nums[location-1]>=1  nums[location-2]>=2
....依次循环
如果location = 0的时候，返回true,如果遍历完之后仍然没有结果，返回false

### 代码

```cpp
class Solution {
public:
    bool canJump2(vector<int>& nums, int location){
        if(location == 0)
        return true;

        for(int i = location -1; i >= 0; i--)  //是否=0值得再考虑
        {
            if(nums[i] >= location - i)
            return canJump2(nums, i);
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int lens = nums.size();
        if(lens == 0 || lens == 1)
        return true;
        int location = lens-1; //终点在数组中的位置
        return canJump2(nums,location);

    }
};
```