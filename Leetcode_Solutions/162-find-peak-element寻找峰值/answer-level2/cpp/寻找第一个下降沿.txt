### 解题思路
思路很简单：
因为数组边界的高度是-∞，因此从边界到nums[0]是一个上升沿，如果nums[0]>nums[1]，那么nums[0]就是一个峰值；
如果nums[0]<nums[1]，那么从边界到nums[1]也是一个上升沿，继续判断num[1]>nums[2]?；
以此类推，我们只需要从index=0开始一直找即可，一旦出现一个下降沿就说明找到峰值，由于末尾元素和右侧边界一定构成下降沿，所以这个峰值是必然存在的。

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size()-1 || nums[i] > nums[i+1])
                return i;
        }
        return -1;
    }
};
```