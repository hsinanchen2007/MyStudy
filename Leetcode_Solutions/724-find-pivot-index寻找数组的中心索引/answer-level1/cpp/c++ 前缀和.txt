### 解题思路
前缀和

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //计算整个数组数之和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(leftSum == sum - leftSum - nums[i]){
                return i;
            }
            //前缀和
            leftSum += nums[i];
        }
        return -1;
    }
};
```