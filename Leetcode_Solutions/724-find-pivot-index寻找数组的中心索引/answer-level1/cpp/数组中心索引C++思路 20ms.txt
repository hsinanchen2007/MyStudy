### 解题思路
新手解题。执行时间：**20MS** 。数组为空直接返回-1，一个元素返回0.
1. 计算数组和sum。
2. 遍历数组，每个循环累加sumleft,并判断sumright ?= sum-sumleft-当前元素。
3. 若是直接返回，否则回到第二步。

### 代码

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
     if (nums.size() == 0) {
         return -1;
     }else if (nums.size() == 1) {
         return 0;
     }
     int sum=0;
     for (int i=0;i<nums.size();i++) {
         sum +=nums[i];
     }
     
     int sumleft =0,sumright = sum -sumleft;
     for (int i = 0;i<nums.size();i++) {
        
        sumright = sum - sumleft - nums[i];
        if (sumleft == sumright) {
            return i;
        }
        sumleft +=nums[i];

     }
     return -1;
    }
};
```