### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=i-nums[i];
    return sum+n;
    }
};
```