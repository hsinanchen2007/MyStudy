### 解题思路
快速算法，当sumLeft*2==sumTotal-nums[j]时，j为中心索引
### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
            int sumLeft=0;//索引左边数组元素的和
            int sumTotal=0;//数组所有元素的和
        for(int i=0;i<nums.size();i++)
            sumTotal+=nums[i];
        for(int j=0;j<nums.size();j++)
        {
          if(sumLeft*2==sumTotal-nums[j])
              return j;

            sumLeft+=nums[j];
        }
        return -1;
    }
};
