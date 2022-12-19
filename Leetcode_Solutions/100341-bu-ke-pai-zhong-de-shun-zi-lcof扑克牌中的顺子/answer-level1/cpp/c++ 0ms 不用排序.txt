### 解题思路
一共只有5个数构成顺子必须不能有非0的重复
如果最大减最小大于等于5 则必然出现空隙
除此之外必然所有情况都满足条件

欢迎大家关注我的leetcode仓库～
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
[我的SICP习题解答](https://github.com/wfnuser/sicp-solutions/)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流


### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int upper = -1;
        int lower = 100;

        for (auto num: nums) {
            cnt[num]++;
            if (num != 0) {
                if (cnt[num] > 1) return false;
                upper = max(upper, num);
                lower = min(lower, num);
            }
        }

        if (cnt[0] >= 4) return true;
        int delta = upper - lower;
        if (delta >= 5) return false;

        return true;        
    }
};
```