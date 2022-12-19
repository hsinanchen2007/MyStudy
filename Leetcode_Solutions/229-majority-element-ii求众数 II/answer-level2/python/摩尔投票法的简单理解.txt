* 与[169. 多数元素](https://leetcode-cn.com/problems/majority-element/solution/majority-element-by-coldme-2/)的两点区别：
    * “多数”是指超过n/3，不是n/2，因此最多会有两个元素是众数，**要建立两个`candidate`**
    * 题目没保证多数元素一定存在，所以**最后要对`candidate`进行检验**。因此整个流程分为两步：step1投票阶段，step2检验阶段。
* 算法核心：
    * 对于候选者`cand1`和`cand2`：
        * 如果投`cand1`，`cand1`加一票。
        * 如果投`cand2`，`cand2`加一票。
        * 如果投其他元素，`cand1`和`cand2`各减一票。
* 理解方法：
    * 在[169. 多数元素](https://leetcode-cn.com/problems/majority-element/solution/majority-element-by-coldme-2/)中，
        * 如果`candidate`是多数元素，那么`多数元素（>n/2）`与`其他元素之和（< n/2）`对抗，一定赢。
        * 如果`candidate`不是多数元素，那么`该元素（< n/2）`与`多数元素和其他元素之和（>n/2）`对抗，一定会被打败。
    * 本题中，分为`A``B``others`三个阵营
        * 如果此刻`candidate`是`A`和`B`，那么`A（>n/3）`与`others（<n/3）`对抗稳赢，`B（>n/3）`与`others（<n/3）`对抗稳赢。
        * 如果此刻`candidate`是`A`和`C`（`C`来自`others`），那么`B``C`一定是对抗不了`B`的。
* 时间复杂度O(n)，空间复杂度O(1)
```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1, vote1 = None, 0
        cand2, vote2 = None, 0
        res = []
        # step1 vote
        for i in range(len(nums)):
            if cand1 is None and cand2 != nums[i]:
                cand1 = nums[i]
                vote1 = 1
            elif cand2 is None and cand1 != nums[i]:
                cand2 = nums[i]
                vote2 = 1
            else:
                if cand1 == nums[i]:
                    vote1 += 1
                elif cand2  == nums[i]:
                    vote2 += 1
                else: 
                    vote1 -= 1
                    vote2 -= 1
                    if vote1 == 0:
                        cand1 = None
                    if vote2 == 0:
                        cand2 = None
        # step2 check
        vote1, vote2 = 0, 0
        if cand1 is not None:
            for i in range(len(nums)):
                if cand1 == nums[i]:
                    vote1 += 1
        if cand2 is not None:
            for i in range(len(nums)):
                if cand2 == nums[i]:
                    vote2 += 1
        if vote1 > len(nums)//3:
            res.append(cand1)
        if vote2 > len(nums)//3:
            res.append(cand2)
        return res
```