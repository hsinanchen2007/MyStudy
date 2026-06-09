### 解题思路
根据评论区点赞第一的生动例子。每次移动一个数，另外n-1个数+1，换个角度，每次移动一个数，这个数就减一。所以所有数字与数组中最小值的差值的和就是最小移动次数。

### 代码

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int num=0;
        
        sort(nums.begin(),nums.end());
        
        int min=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            num+=nums[i]-min;
        }
        
        return num;

    }
};
```