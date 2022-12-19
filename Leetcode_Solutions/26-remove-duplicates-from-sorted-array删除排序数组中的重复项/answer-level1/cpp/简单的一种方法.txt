### 解题思路
概述：只需要三个函数，即可对数组，或其他容器进行去重；
sort(), unique(), erase();
1. sort对数组进行排序；本题已经排序，无需调用；
2. unique对数组进行去重，重复的数字，被移到末尾，返回一个指向不重复范围末尾的迭代器；
3. erase删除末尾重复的数字；
打完收工

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator end_unique = unique(nums.begin(), nums.end());
        nums.erase(end_unique, nums.end());
        return nums.size();
    }
};
```