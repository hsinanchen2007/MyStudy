### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0; 
        int j = n-1;
        int cur = 0;
        while(cur <= j) {
            if (nums[cur] == 0) {
                swap(nums[cur++], nums[i++]);
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[j--]);
            } else {
                cur++;
            }
        }
        return;
    }
};
```