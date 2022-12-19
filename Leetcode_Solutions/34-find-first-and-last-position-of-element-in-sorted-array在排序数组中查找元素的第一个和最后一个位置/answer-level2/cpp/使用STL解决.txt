### 解题思路
利用STL中lower_bound和upper_bound函数解决
step1：容器为空时，初始化容器vector<int>{-1,-1}返回容器{-1,-1}
step2：调用STL中的lower_bound函数返回第一个大于等于target位置的迭代器left；使用STL中的upper_bound函数返回第一个大于target的位置的迭代器right
step3：若left == right表明找到的是大于target的数，left == nums.end()时说明target比数组所有元素大，这两种情况下均没有找到，则返回{-1,-1}，否则，返回{left - nums.begin(), right - nums.begin() - 1}

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*方法1：普通方法
        int left = -1, right = -1;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(left == -1 && nums[i] == target) left = i;
            if(nums[i] == target) right = i;
        }
        res.push_back(left);
        res.push_back(right);
        return res;
        */
        //方法2：利用STL中lower_bound和upper_bound函数解决
        if(nums.empty()) return vector<int> {-1, -1};
        vector<int>::iterator left = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator right = upper_bound(nums.begin(), nums.end(), target);
          if(left == right || left == nums.end()) 
             return {-1, -1};
          else
             return {left - nums.begin(), right - nums.begin() - 1};
    }
};
```