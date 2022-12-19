### 解题思路

从后向前遍历，如果可到达则截取
截取第一个可到达的节点，可保证全局最优（原因：此节点到不了，其他也到不了）

### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = 1;
        bool tag = false;
        for(int i = n-2; i>= 0; i--){
            if(nums[i] >= m) m = 1;
            else m++;
        }
        if(m == 1) tag = true;
        return tag;
    }
};
```