### 解题思路
本题与题目 [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)
[面试题39. 数组中出现次数超过一半的数字](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/) 题目一样。

都是采用对杀法。需要注意的是细节部分：
例如，对于  2,2,2,1,1,1,1  当处理到最后一个 1 前，count==0, 表示前面全部抵消，此时 cur 还没有变。处理最后 1， count = -1。 接着判断，count < 0， 于是取 cur = x， count = 1。

但题解169题解 count==0 时换元素，居然也对,很奇怪。 [gelthin-血量](https://leetcode-cn.com/problems/majority-element/solution/xie-liang-by-gelthin/)


### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        l = len(nums)
        if l==0:
            return None
        if l==1:
            return nums[0]

        cur = nums[0]        
        count = 1
        for x in nums[1:]:
            if cur == x:
                count += 1
            else:
                count -= 1
                if count < 0:  # 细节，是 count ==0, 还是 count <0
                    cur = x
                    count = 1
        
        if count >= 1:
            return cur
        else:
            return -1

```