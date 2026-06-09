### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (nums[i]>=1&&nums[i]<=nums.size() && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]) {
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
            if (nums[i]<1 || nums[i]>nums.size()) {
                nums[i] = -1;
            }
        }
        int ans = -1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=i+1) {
                ans = i+1;
                break;
            }
        }
        if (ans==-1) {
            ans = nums.size()+1;
        }
        return ans;
    }
};
```