### 思路：数学
逆向思维，每次讲n-1个数增加1，效果等价于未被选中的数减1，比如[1, 2, 3]，给出去最大数增加1后[2, 3, 3]，我们全体减1变为[1, 2, 2]并不影响数字直接的相对差值，这个结果就是原始数组中最大数减1，所以可以将问题转化为所有数减小到最小数，累加每个数和最小数之间的差值即可。

### 代码

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, mn = INT_MAX;
        for (int n : nums) mn = min(n, mn);
        for (int n : nums) res += n - mn;
        return res;
    }
};
```