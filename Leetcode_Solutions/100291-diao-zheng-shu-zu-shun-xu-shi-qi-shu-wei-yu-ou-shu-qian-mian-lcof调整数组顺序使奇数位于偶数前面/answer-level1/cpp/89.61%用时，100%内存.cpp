### 解题思路
双指针法

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left,right;
        int swap;
        left = 0;
        right = nums.size() - 1;
        if(right<=0)
            return nums;
        while(left!=right){
            if(nums[left]%2==1){
                ++left;
                continue;
            }
            if(nums[right]%2==0){
                --right;
                continue;
            }
            swap = nums[left];
            nums[left] = nums[right];
            nums[right] = swap;
        }
        return nums;
    }
};
```