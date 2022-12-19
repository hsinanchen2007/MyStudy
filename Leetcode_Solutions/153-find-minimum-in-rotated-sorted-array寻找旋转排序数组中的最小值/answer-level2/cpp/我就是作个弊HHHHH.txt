### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int p;
        for(int i = 0; i < nums.size(); i++) {
            int k = i;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[k] > nums[j]) {
                    k = j;
                }
            }
            return nums[k];
        }
        return nums[0];
    }
};
```