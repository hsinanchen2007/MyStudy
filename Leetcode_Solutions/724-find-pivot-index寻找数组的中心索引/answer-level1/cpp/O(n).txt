### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        if(nums.size()==0)return -1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int p=0;
        for(int i=0;i<nums.size();i++){
            if(p==(sum-p-nums[i]))return i;
            p+=nums[i];
        }
        return -1;
    }
};
```