![image.png](https://pic.leetcode-cn.com/209b49d3e78176f281588e275e0926e7c830a97035c10390989c7b650b7d4f89-image.png)

### 解题思路
通过STL的库函数upper_bound()、lower_bound()实现. 思路见注释

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target); //找到第一个不小于target的数(若有target, 则返回第一个target的迭代器)
        if(first == nums.end() || *first != target)  return {-1,-1};//若均小于target或没有等于target的数
        auto last = upper_bound(nums.begin(), nums.end(), target); //找到第一个大于target的数
        return {int(first - nums.begin()), int(last - nums.begin() - 1)}; //返回索引
    }
};
```