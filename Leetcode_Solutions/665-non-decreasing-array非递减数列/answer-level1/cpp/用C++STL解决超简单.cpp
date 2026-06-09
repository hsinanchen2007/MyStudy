### 解题思路

is_sorted_until函数是algorithm库里面的函数，用于查找范围内的第一个未排序元素，比如说对1，3，2使用这个函数就返回指向2的迭代器
，其实就是找到第一个比前一个数小的数，然后返回迭代器，如果给的数组长度小于2(我们在程序中通过这个特性特判系统给出数组长度为1的情况)或者没有找到符合的数(数组已经升序排序)，那么就返回超越末端迭代器(vec.end())。

is_sorted函数用来判断数组是否已经按升序排序


第一个if就是根据is_sorted_until是否返回超越末端迭代器特判数组长度为1的情况
第二个if是判断当is_sorted_until找到的值位于数组末尾的情况(超越末端迭代器指向数组末尾元素之后)
第三个if是判断is_sorted_until找到的值位于数组中，而且该值右侧大于左侧
最后是当这个值左侧值大于右侧

每个if判断完都会对数组中的元素进行相应的修改，如果修改完以后数组按升序排序了，那么就返回true
否则(一次修改依然无法满足升序)返回false



### 代码

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        ios::sync_with_stdio(false);
        vector<int>::iterator it = is_sorted_until(nums.begin(), nums.end());
        if (it == nums.end())
            return true;
        if (it + 1 == nums.end())
            *it = INT_MAX;
        else if (*(it + 1) > *(it - 1))
            *it = *(it + 1);
        else
            *(it - 1) = *it;
        return is_sorted(nums.begin(), nums.end());
    }
};
```