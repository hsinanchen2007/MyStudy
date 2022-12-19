### 解题思路
设定循环不变式为 "maxJump 表明最大能跳到的距离"
1.如果i不在maxJump 的范围内，表明当前无法跳到
2.如果在maxJump范围内，计算当前所能跳跃到的距离和maxJump比较，替换成更大的
3.循环结尾看maxJump是否超过数据长度
PS：因为数组内是上限，所以用一个数字就可以，如果是能够跳的补数，那么使用一个数组


### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
    if (nums.size()==1)return true;
    int maxJump = 0;    //最远距离 小于这个数量的默认可达
    for(int i=0;i<nums.size();++i){
        if (i<=maxJump)
            if((i+nums[i])>maxJump)
                maxJump=nums[i]+i;
    }
    return maxJump>=nums.size()-1?true:false;
    }
};
```