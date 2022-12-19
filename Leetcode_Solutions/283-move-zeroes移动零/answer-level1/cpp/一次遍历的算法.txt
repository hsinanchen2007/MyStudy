### 解题思路
边遍历边将非0元素往前放，遍历结束后将数组剩余部分用0填充。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //在i遍历完之前，遇到0则将其靠前放，i遍历完后，剩余数组元素填充0
        for(int i = 0, j = 0; j < nums.size(); i ++) {
            if(i < nums.size() && nums[i] != 0) {
                nums[j ++] = nums[i];
            }
            //i遍历结束
            else if(i >= nums.size()){
                nums[j ++] = 0;
            }
        }
    }
};
```