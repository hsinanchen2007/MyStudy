感觉最高赞写的位运算有许多人不是太明白怎么回事，这里详细说明一下。
首先，这道题可以使用位运算的原理是：数组中每个位置的数都有“选与不选”两种状态，因此可以用二进制进行状态压缩。
对于下面的代码来说，i的含义其实就是枚举了所有的情况。
假设 n=3. 那么就有2^(n-1)种情况。因此 i<(1<<n) 其实就是 i<2^3.
i = 0 : 0 0 0
i = 1 : 0 0 1
i = 2 : 0 1 0
i = 3 : 0 1 1
i = 4 : 1 0 0
i = 5 : 1 0 1
i = 6 : 1 1 0
i = 7 : 1 1 1

第二层循环 j 的含义就相当于将i的二进制变现。
i>>j 表示i右移j位，其实也就是锁定到i二进制位中从右往左第j+1的位置。
比如说i = 3时：
3>>0 对应最低位的1.
3>>1 对应从右往左第2位的1.
3>>2 对应从右往左第3位的1.

(i>>j)&1 表示判断 (i>>j)位置是否为1。
假设 i = 110(二进制)，j = 1. 此时i>>j = 11 (i右移1位)
11 & 01 = 01 = 1 = true. 这样就可以获取到i从右往左第j+1的位置是否为1了。

这样，就可以将所有的i二进制位，即枚举的所有情况实现。
更多的位运算操作可以参考这篇博客：[https://blog.csdn.net/Skyed_blue/article/details/102828308](https://blog.csdn.net/Skyed_blue/article/details/102828308)


```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i < (1<<n);i++)
        {
            vector<int> t;
            for(int j = 0;j < n;j++)
            {
                if((i>>j)&1 == 1) t.push_back(nums[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
```
