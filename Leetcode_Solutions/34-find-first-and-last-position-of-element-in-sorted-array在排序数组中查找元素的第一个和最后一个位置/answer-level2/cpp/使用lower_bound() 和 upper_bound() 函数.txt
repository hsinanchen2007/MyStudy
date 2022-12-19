使用了c++ 定义于<algorithm>中的 `lower_bound()` 和 `upper_bound()` 函数

函数功能：
lower_bound(): 指向首个不小于 value 的元素的迭代器，或若找不到这种元素则为 last
upper_bound(): 指向首个大于 value 的元素的迭代器，或若找不到这种元素则为 last 
> 具体看 [https://zh.cppreference.com/w/cpp/algorithm/lower_bound](https://zh.cppreference.com/w/cpp/algorithm/lower_bound)

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        //查找第一个大于或等于target的元素的迭代器
        auto it_begin = lower_bound(nums.begin(), nums.end(), target);
        //如果找到且等于target
        if(it_begin != nums.end() && *it_begin == target)
            ans[0] = it_begin - nums.begin();
        //查找第一个大于target的元素的迭代器
        auto it_end = upper_bound(nums.begin(), nums.end(), target);
        //当nums只有一个元素时且大于或等于target时，it_end肯定会指向nums.end()
        //                    小于时，nums.begin() == it_end，此时返回-1
        if(it_end != nums.begin() && *(it_end - 1) == target)
            ans[1] = it_end - nums.begin() - 1;
        return ans;
        
    }
};
```
如果想自己写不想使用库函数的话，可以自行实现 `lower_bound()` 和 `upper_bound()` 函数

```c++
int lower_bound(vector<int>& nums, int target)
{
    int low = 0, high = nums.size();
    while(low < high)
    {
        int mid = low + (high - low >> 1);
        if(nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upper_bound(vector<int>& nums, int target)
{
    int low = 0, high = nums.size();
    while(low < high)
    {
        int mid = low + (high - low >> 1);
        if(nums[mid] <= target) //其实就一个等号的区别
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
```
