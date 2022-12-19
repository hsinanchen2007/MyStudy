### 解题思路
找到第一个大于目标值的数值，如果原数组里有target值，则返回对应下标；如果没有则返回插入下标

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int i,j;
        i = 0;
        while(i<nums.size() && nums[i]<=target) i++;
        
        cout<<i<<endl;

        if(i>0 && nums[i-1]==target)i = i-1;

        return i; 
    }
};
```