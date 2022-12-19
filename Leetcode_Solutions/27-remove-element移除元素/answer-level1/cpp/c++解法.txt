### 解题思路
遍历一遍，如果nums[i]==val，则删除，否则留下。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0;i<nums.size();i++) if(nums[i]==val) nums.erase(nums.begin()+i),i--;
        return nums.size();
    }
};
```