这道题我的想法是: **每次记录可以跳到最远位置的索引值**

例如以题目给的为例 `[2 3 1 1 4]`

```
ans = =cur = 0
cur 表示当前指针的位置
() 中的元素表示能够够到的位置
-----------------------第一次
[2  (3   1)  1   4]
 cur
ans = 1
----------------------- 第二次
[2   3   (1   1   4)]
     cur
ans = 2
```
第一次我们的指针在`0`处, 步长为2,所以我们能够够到的索引为`{1, 2}`
发现在`1`处的元素`3`, 可以让我们蹦的更远(可以蹦到索引4), 所以我们记录指针的下一个位置为`1`
第二次指针在`1`处, 步长3, 我们发现能够够到最后一个索引, 退出循环即可

代码总结如下
```python3
class Solution:
    '''
    贪心算法
    '''
    def jump(self, nums: List[int]) -> int:
        last_idx = len(nums) - 1
        if last_idx < 1:
            return 0
        ans = 0
        cur = 0
        # 此处跳出循环的时候, 注意返回值是 ans + 1
        # 因为虽然跳出了, 要补上最后一步
        while cur + nums[cur] < last_idx:
            # 记录当前步长
            step_len = nums[cur]
            # tmp 记录能访问到的最远距离
            tmp = 0
            # 走一步
            ans += 1
            for _ in range(1, step_len + 1):
                if cur + _ + nums[cur + _] > tmp:
                    tmp = cur + _ + nums[cur + _]
                    # 记录下一次循环的'当前位置'
                    # 当前位置指的是从这个位置跳,距离最远
                    idx = cur + _
            cur = idx
        return ans + 1

```
