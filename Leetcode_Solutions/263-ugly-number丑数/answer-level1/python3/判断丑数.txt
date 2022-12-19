### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/fe0afc1e719aab016f824f4bf7d598db57d8d323eae8d5eec6254c946962980c-%E6%8D%95%E8%8E%B7.PNG)
很自然想到依次剔除输入质因数中的2，3，5

### 代码

```python3
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False
        factor=iter([2,3,5,6])
        a=factor.__next__()
        while num>1:
            (num,a)=(num//a,a) if num%a==0 else (num,factor.__next__())
            if a>5:
                return False
        return True

```