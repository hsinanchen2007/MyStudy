### 解题思路
给需要C++的童鞋。快慢指针，一遍扫描。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();

        int i=0, j=0;
        for (j=0; j < nums.size(); j++) {
            if(nums[j] != nums[i]){  // 不等的话说明有一个新的数了
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1; // 下标从0开始，所以长度要+1
    }
};
```