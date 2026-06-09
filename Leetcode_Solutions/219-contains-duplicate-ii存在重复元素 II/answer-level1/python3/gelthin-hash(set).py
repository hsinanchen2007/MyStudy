### 解题思路
这一题有很多解法：
+ 排序时保留下标位置，然后遍历判断
+ 使用 hash 表+队列保留至多k个元素，当超过k个元素，则删去最先进入的元素
+ 使用 hash 表，可能保留所有元素，当碰到新元素时，更新下标。

官方题解可以学会很多东西。
python3 中 hash 指 set() 或者 dict()

使用 dict() 最多保留 n 个元素，如果已经存在，则判断是否下标间隔为 k, 如果不存在，则


参考此题解 [哈希（套路）逐行解释 python3](https://leetcode-cn.com/problems/contains-duplicate-ii/solution/ha-xi-tao-lu-zhu-xing-jie-shi-python3-by-zhu_shi_f/)

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        A_dict = dict()
        for i, x in enumerate(nums):
            if x in A_dict.keys():
                if i - A_dict[x] <= k:
                    return True
                else:  # 这一步可以合并到下面，但为了逻辑清晰，还是保留
                    A_dict[x] = i
            else:
                A_dict[x] = i
        return False
```