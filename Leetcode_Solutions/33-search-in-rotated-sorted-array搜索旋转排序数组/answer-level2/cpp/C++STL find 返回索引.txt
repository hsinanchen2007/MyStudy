### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        vector<int>::iterator it;
        it = find(nums.begin(),nums.end(),target);
        if(it==nums.end())
        {
            return -1;
        }
        else
        {
            auto index = &*it-&nums[0];
            return index;
        }
        
    }
};
```