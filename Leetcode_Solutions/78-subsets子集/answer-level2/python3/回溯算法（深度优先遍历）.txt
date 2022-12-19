
![sub.png](https://pic.leetcode-cn.com/013341b812f75a5be2486bccf553bc2e45e59ca12242b2b36c16105516367fc5-sub.png)
幂次子集：有n个数，它的子集有2的n次幂
采用深度优先遍历的思想，将n个数，分别做为根结点，构造二叉树，根结点的孩子分别是根结点之后的所有数，依此作为递归体。
算法步骤：
i作为父亲结点，first为孩子结点,初始值均为0
迭代nums中所有数,：
    - 将nums[i]放入temp之后
    - 迭代temp元素将其放入output中
    - 递归遍历backtrace(i+1)
    - 将其temp中元素删除
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrace(first):
            for i in range(first, len(nums)):
                temp.append(nums[i])
                output.append([value for value in temp])
                backtrace(i + 1)
                temp.pop()
        temp = []
        output = []
        backtrace(0)
        output.append([])
        return output
```
