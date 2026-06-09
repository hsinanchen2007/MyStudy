### 代码

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for(int i=0;i<n-1;i++){
            if(!nums[i]){
                if(m<=i) return false;
            }
            m = max(nums[i]+i,m);
        }
        return true;
    }
};
```