### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
            if(nums.size()<2)
                return 0;
        set<int> temp;
            for(int i=0;i<nums.size();++i){
                if(temp.find(nums[i])==temp.end())
                    temp.insert(nums[i]);
                else
                    return nums[i];
        }
        return 0;
    }
};
```