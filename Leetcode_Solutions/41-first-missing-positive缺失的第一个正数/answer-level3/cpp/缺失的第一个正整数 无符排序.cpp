无符号排序，然后依次查找最小无符正整数。
其实也可以考虑改为有符号排序。


```cpp
class Solution {
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int min = 1;
        sort(nums.begin(), nums.end(), [](int a, int b){return (unsigned int) a < (unsigned int) b;});
        if (nums.size() == 0 || nums[0] < 0) { return 1; }
        for (auto n: nums) {
            // 略过 0
            if (n == 0) { continue; }
            // 负数排在后面，到达负数就可以停止了
            if (n < 0) { return min; }
            // min比n小，说明n已经有跳跃，中间空挡最小数就是我们要的了。
            if (min < n) { return min; }
            // min设置为比当前数大1
            min = n + 1;
        }
        return min;
    }
};
```
