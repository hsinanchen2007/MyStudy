![image.png](https://pic.leetcode-cn.com/ca21fc5e84fff86b098f419a0c1a061fd4f5e50c78730e88e5f32ab7a564c0fc-image.png)


## 题目分析

显然后面的结果依赖于前面的值，所以需要一些额外空间记录数据。

记`a(n)`为第n个预约的时间
记`f(n)`为预约集合中最后一个预约为第n个预约时的最大预约时间。
可知`f(1) = a(1), f(2) = a(2), f(3) = a(1) + a(3), f(4) = max(f(1), f(2)) + a(4)`

记`S(n)`为长度为n的的预约序列的最大预约时长
可知`S(1) = f(1), S(2) = max(f(1), f(2)), S(3) = max(f(2), f(3))`

分析题目可知，最优预约集合最多跳过连续两个预约，因为如果跳过了连续3个，那中间那个总可以加上使总时长增加。

所以计算`f(n)`时只需要考虑`f(n-3)`和`f(n-2)` (不能连续两个，所以不考虑`f(n-1)`)。

递推公式为：

`f(n) = max(f(n-3), f(n-2)) + a(n), (n >= 4)`

`S(n) = max(f(n-1), f(n)), (n >= 2)`


## 代码
写成迭代形式

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int fn = 0, fn_1 = 0, fn_2 = 0, fn_3 = 0;
        int size = nums.size();
        for(int i = 0; i < size; ++i) {
            fn_3 = fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
            fn = max(fn_3, fn_2) + nums[i];
        }
        return max(fn_1, fn);
    }
};
```