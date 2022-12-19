### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),a=n;
        for(int i=0;i<n;i++){
            a^=i;
            a^=nums[i];
        }
        return a;

    }
};
```