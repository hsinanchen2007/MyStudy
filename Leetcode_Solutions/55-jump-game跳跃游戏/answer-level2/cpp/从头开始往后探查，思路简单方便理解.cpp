### 解题思路
从头遍历数组，可能在中间就结束了，不需要完整遍历，速度还是可以的。
right记录当前位置可以往后跳到的位置的下标，当前位置能往后跳 i + nums[i]这么远。
right = max(right, i + nums[i])
由于right可能大于数组长度-1，所以构建range来表示可以访问的数的范围。
range = min(range, nums.size() - 1) i只能在这个范围内取值
当范围到达了最后一位，就输出true。


### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;//记录当前位置可往后跳到的位置（可能大于数组长度）
        int range = 0;//记录能访问的到的数组的最后的位置
        for(int i = 0; i <= range; i++) {//i小于能访问的范围
            right = right >= i + nums[i] ? right : i + nums[i];//能探查的最远距离
            range = nums.size() - 1 >= right ? right : nums.size() - 1;//right可能大于数组长度-1
            if(range == nums.size() - 1)//最后一位包含在范围内
                return true;
        }
        return false;
    }
};
```