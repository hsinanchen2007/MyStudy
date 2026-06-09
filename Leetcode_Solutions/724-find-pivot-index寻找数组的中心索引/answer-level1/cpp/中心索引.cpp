### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,leftsum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        for(int i=0;i<nums.size();i++){
            if(2*leftsum==sum-nums[i])
            return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};
```