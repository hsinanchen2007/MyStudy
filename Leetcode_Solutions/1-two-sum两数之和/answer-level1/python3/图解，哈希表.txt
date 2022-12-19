# 1. Two Sum
### 解题思路
通过迭代将元素添加到哈希表中，同时我们比较该元素的对应元素是否已经存在与哈希表中，如果存在，我们直接返回答案。

<![幻灯片1.JPG](https://pic.leetcode-cn.com/e6c5428c477ba81f0e139a81ae970413615e8ec2c6d684833eb6c550606dd545-%E5%B9%BB%E7%81%AF%E7%89%871.JPG),![幻灯片2.JPG](https://pic.leetcode-cn.com/c60fa8e8788ca780afedef31b38535c1d91d7e690d7aee5d892a1b0077db95af-%E5%B9%BB%E7%81%AF%E7%89%872.JPG),![幻灯片3.JPG](https://pic.leetcode-cn.com/27437b90a95fcf0544018e69af70f4888698b745ceefa7606a7c8ea0136da68c-%E5%B9%BB%E7%81%AF%E7%89%873.JPG),![幻灯片4.JPG](https://pic.leetcode-cn.com/47a33154b3ed1c4e1d7340e6e14543d9cca73504cffd3ef49ecb81fa2b1f82b8-%E5%B9%BB%E7%81%AF%E7%89%874.JPG)>


### 代码

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for idx, num in enumerate(nums):
            if target - num in hashmap:
                return [hashmap[target - num],idx]
            else:
                hashmap[num] = idx
```
### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。



### 相关题目
不妨我们趁热打铁，看看进阶题目！
- [15.三数之和](https://leetcode-cn.com/problems/3sum/)
- [18.四数之和](https://leetcode-cn.com/problems/4sum/)
- [454.四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)