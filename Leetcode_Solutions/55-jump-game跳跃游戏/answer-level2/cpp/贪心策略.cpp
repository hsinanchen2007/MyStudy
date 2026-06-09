### 解题思路
1. 判断当前位置是否能跳到末尾。若能返回true，若不能，下一步；
2. 当前位置pos下允许的最远位置为 pos+nums[pos]， 在pos+1 -> pos+nms[pos]中寻找这样一个位置next， 使得从next出发能达到最远；
3. 以next作为新的pos,重复1、 2.

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos=0;
        while(pos<nums.size()-1)
        {   
            if(nums[pos]==0) return false;
            if(nums[pos]+pos>=nums.size()-1) return true;
            int dist = nums[pos];
            int temp_max = pos;
            int next = pos+1;
            for(int i=pos+1;i<=pos+dist && i<nums.size();i++)
            {
                if(i+nums[i]>temp_max) {
                    next =i;
                    temp_max = i+nums[i];
                }
            }
            pos = next;
        }
        return true;
    }
};
```