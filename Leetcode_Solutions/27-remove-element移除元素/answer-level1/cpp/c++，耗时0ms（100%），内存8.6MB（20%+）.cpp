*（第一次写题解，有点激动hhh）*

内存我不知道什么情况，但是耗时用了一个小trick。

我们看题目中明确提到**不考虑元素的顺序，且不考虑新长度之后的元素的情况**，于是我们可以考虑：先存一下原数组的长度len，从前往后遍历元素，下标为pos，遇到和val相同的元素，就将nums[len-1]置给nums[pos]，然后len自减。由于多余的元素不考虑，我们甚至都不需要erase掉末尾元素。然后如果刚刚有删除操作，那么pos不变化，因为我们不知道原先nums[len-1]那里是不是等于val；如果没有删除操作，就pos自增。反复操作直到pos和len重合，返回len。

讲话讲不清楚，参看代码：
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int pos = 0;
        while (pos < len) {
            if (nums[pos] == val)
                nums[pos] = nums[--len];
            else
                ++pos;
        }

        return len;
    }
};
```

PS：这种方法也可以解决洗牌问题，只不过每次的判断操作换成随机抽下标。如果您还看过python的源代码，python的随机洗牌函数运用的就是这种方法，效率很高。

PSS：我感觉耗时0ms太假了，是不是我眼瞎看错了？？？