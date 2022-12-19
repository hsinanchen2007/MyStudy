### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i])
                count++;
            else{
                res = max(res,count);
                count = 0;
            }
        }
        return max(res,count);
    }
};
```