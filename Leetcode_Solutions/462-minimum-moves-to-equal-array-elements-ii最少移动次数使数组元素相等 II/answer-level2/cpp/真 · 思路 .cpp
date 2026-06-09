### 解题思路
题意: 对于任意数组有序 a[n]
假定存在一个值 x 使得最优解 Σ (x - a[i]) + (a[j] - x) 最小

画图 + 猜测 : 
![image.png](https://pic.leetcode-cn.com/1a0b231e91cfa9fe0e0392563d24ac6c0d16fa8dc9821367c6855cafcdc3ad17-image.png)
当 x 越偏中,黄色部分面积越小
从 S = 长 * 高
长和高存在函数对应关系,当 x 趋近于 n / 2 位置,面积越小 

列式子 + 猜测 : 
我们可以列出 x 在 a[n] 内的大小 : 0 ~ n + 1
通过列式分析,可得 x == n/2 位置最优
举例子
a1 < a2 < a3 < a4
如果 x 在 a1 < x < a2 之间
sum = (x - a1) + (a2 - x) + (a3 - x) + (a4 - x) 
    = (a4 - a1) + (a2 + a3) - (x - x)
如果 x 在 a2 ~ a3 之间
sum = (x - a1) + (x - a2) + (a3 - x) + (a4 - x)
    = (a4 - a1) + (a3 - a2)
比较这 2 个式子
式1 ____ 式2
a2 + a3 - 2x ____ a3 - a2
2a2 ____ 2x
有题目假设可得 a2 > x
所以式2 更小
猜测当 n = anyvalue 时 x 处于其他位置同理满足

### 代码

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;
        while(l < r) {
            ans += nums[r--] - nums[l++];
        }
        return ans;
    }
};
```