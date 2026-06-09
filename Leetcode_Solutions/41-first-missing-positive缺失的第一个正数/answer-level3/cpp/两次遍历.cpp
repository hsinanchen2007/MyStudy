### 解题思路
需要注意一下第一次遍历时，若当前位置的数需要换出，不要i++。
### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len=nums.size();
        for(int i=0; i<len;)
            if(nums[i]>0 && nums[i]<=len && nums[i]!=nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else ++i;
        for(int i=0; i<len; ++i)
            if(nums[i] != i+1) return i+1;
        return len+1;
    }
};
```