![image.png](https://pic.leetcode-cn.com/41fe786f3a56ae9e523ed4eabbffb1e282e3aa93dce5239d45e753e7fd16dda8-image.png)


```
'''
首先，可以先不看nums, 假设nums是空的，这种情况下要让覆盖的区间大于n要怎么搞？
其实可以发现一个规律，如果[1, x)这个连续区间是已经被nums中可能的数值和覆盖的，
而x是当前最小的缺失的数值的时候，下一次我们可以添加什么值？
显然大于x的值是不可能的，因为这样添加数值之后，新增加的组合的和一定是[1, x)中
一个数加上新增这个数，肯定大于x, 那后面继续添加更大的值，x这个空位永远没法填了
所以当前可以选的值是[1, x]区间里面任何一个值，假设选的是v, 那[1,x)区间覆盖范围
就可以拓展到[1, x+v) 相当于覆盖区间整个右移了v个单位，显然v就取miss_val, 区间
覆盖范围拓展最多，如果nums一开始是空的，每次拓展区间都要花费开销自己加数值，那
用贪心思想来考虑，我们每次都添加最小的缺失值，区间增长最快，次数肯定是最少的

现在再考虑nums初始是有数值的情况，这带来的区别是什么？无非就是当[1, miss_val)
中如果覆盖了nums中某个数值nums[i]时候，这个数值可以直接拿过来用，不用花费开销，直接
把当前区间覆盖范围往右边增加nums[i], 当然每个值只能用一次，所以每一次拓展区间时候
优先用现成的数值来拓展区间，没有可用的现成的值的时候，自己花费开销填一个miss_val
这样贪心搞，最后次数就是最小的，数学的证明官方题解有
'''
from typing import List

class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        # miss_val 表示[1, miss_val)连续区间当前是完全覆盖了的, miss_val是最小缺失值
        miss_val, ans, cur_pos = 1, 0, 0

        while miss_val <= n:
            if cur_pos < len(nums) and nums[cur_pos] <= miss_val:
                # 当前的区间中有现成的数字可以用来拓展空间，就把覆盖区间往右边拓展
                miss_val += nums[cur_pos]
                cur_pos += 1
            else:
                # 没有现成的数可以直接用来拓展空间，自己花费一次开开销添加miss_val
                miss_val *= 2
                ans += 1
        return ans
```
