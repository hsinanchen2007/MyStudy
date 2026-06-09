## 思路
时间复杂度：$O(N)$
空间复杂度：$O(1)$ 代码里面固定为$10^5$
这个所谓$O(1)$实际比$O(N)$占用大

遍历数组，更新下列信息：
* 利用count维护每个数值出现的次数
* 利用times维护出现相同“次数”的不同值的个数
* 利用min维护出现次数最小的值

有四种情况下，代表当前遍历到的区间符合题目条件：
* 有一个数多出现一次，其他数出现次数相同
* 有一个数只出现了一次，其他数出现次数相同
* 数组里面所有的数值都不同
* 数组里面所有的数值都相同


## 代码

```cpp
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        constexpr int MAX = 100000;
        int ret = 1;
        int count[MAX + 1] = {0};
        int times[MAX + 1] = {0};
        int min = 0;
        int index = 0;
        for (auto num : nums) {
            index++;
            static int tmp = 0;
            if (count[num] > 0) {
                times[count[num]]--;
                if (!times[count[num]] && min == count[num]) {
                    min = count[num] + 1;
                }
                count[num]++;
                times[count[num]]++;
                tmp = count[num];
            } else {
                times[1]++;
                count[num] = 1;
                min = 1;
            }
            if (times[min + 1] == 1 && times[min] * min + (min + 1) == index ||
                times[1] == 1 && times[tmp] * tmp + 1 == index ||
                times[1] == index ||
                min == index) {
                ret = index;
            }
        }
        return ret;
    }
};
```