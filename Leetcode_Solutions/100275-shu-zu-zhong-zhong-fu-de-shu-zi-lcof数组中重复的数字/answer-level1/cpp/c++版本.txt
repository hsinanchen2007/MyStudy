### 解题思路
使用了一个辅助数组

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int nsize = nums.size();
        vector<int>a(nsize, -1);
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == a[nums[i]]){
                return nums[i];
            }
            else{
                a[nums[i]] = nums[i];
            }
        }
        return 0;
    }
};
```