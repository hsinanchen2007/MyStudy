### 解题思路
先for循环将原数组去重
然后再判断新数组的元素个数，并返回结果

### 代码

```cpp
#include <algorithm>
class Solution {
public:
    int thirdMax(vector<int>& nums) {   // by me
        sort(nums.begin(), nums.end());
        vector<int> newNums(1);
        newNums[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            if((newNums.back())!=nums[i])
                newNums.push_back(nums[i]);
        
        if(newNums.size()==2) return newNums[1];
        else if(newNums.size()==1) return newNums[0];
        else return newNums[newNums.size()-3];
    }
};

```