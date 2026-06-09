### 解题思路
参考《剑指offer》

首先给数组排序，然后查找0的个数，然后查找空隙的个数，如果0的个数大于等于空隙个数，说明在空隙中可以插入0（任意数字），便可以构成顺子。如果空隙个数大于0的个数，无法构成顺子。如果出现数字成对存在也无法构成顺子
### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // if(nums.empty()) return true;

        int len = nums.size();
        int numberOfZeros = 0;
        int numberOfGaps = 0;

        // 排序
        sort(nums.begin(), nums.end());

        // 统计0的个个数
        for(int i = 0; i < len && nums[i] == 0; ++i){
            numberOfZeros++;    // 统计0的个数
        }

        // 统计间隔的个数
        int small = numberOfZeros;  // 慢指针
        int big = numberOfZeros + 1;    // 快指针

        while(big < len){
            if(nums[small] == nums[big]){
                // 如果有成对的数字，那么一定不是顺子
                return false;
            }
            numberOfGaps += (nums[big] - nums[small] - 1);    // 求间隔数
            // cout << "When big is " << big << ", numberOfGaps is " << numberOfGaps << endl;
            small = big;
            ++big;
        }

        return numberOfGaps > numberOfZeros? false : true;
    }
};
```