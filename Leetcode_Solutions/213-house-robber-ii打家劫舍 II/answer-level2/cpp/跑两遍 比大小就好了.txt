### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    int previousNum = 0;
    int neighborNum = 0;

    neighborNum = nums[0];
    for (int i = 1; i < nums.size() - 1; ++i) {
        int tmp = neighborNum;
        neighborNum = max(neighborNum, previousNum + nums[i]);
        previousNum = tmp;
    }
    if(nums.size() == 1){
        return neighborNum;
    }
    int previousNum2 = 0;
    int neighborNum2 = nums[1];
    for (int i = 2; i < nums.size(); ++i) {
        int tmp = neighborNum2;
        neighborNum2 = max(neighborNum2, previousNum2 + nums[i]);
        previousNum2 = tmp;
    }
    
    return max(neighborNum, neighborNum2);
}
};
```