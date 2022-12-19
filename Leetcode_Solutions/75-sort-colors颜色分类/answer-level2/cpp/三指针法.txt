### 解题思路
**C++**
执行用时击败100%
![image.png](https://pic.leetcode-cn.com/0065d2e705a19d0aa20318ba03228ccc5a0289707143c41c5ed1751a6725b795-image.png)

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,cur=0,k=nums.size()-1;
        for(;cur<=k;cur++)
        {
            if(nums[cur]==0)
                swap(nums[i++],nums[cur]);
            else if(nums[cur]==2)
                swap(nums[k--],nums[cur--]);
                
        }
    }
};
```