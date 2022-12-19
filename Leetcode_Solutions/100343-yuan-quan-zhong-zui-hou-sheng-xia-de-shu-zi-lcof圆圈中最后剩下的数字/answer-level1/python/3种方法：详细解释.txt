
## 解法一（暴力法）
思路：使用数组申请一块内存（也可以使用链表），按照要求循环执行n-1次移除操作，最后剩下的元素即为所求

1. 申请一块连续内存，存放0到n的数值
2. 位置索引按照题目要求计算，数组中索引从0开始，需要根据移动个数减一
3. 最后一个数值即为所求
* 时间复杂度：O(n)
* 空间复杂度：O(n)
```python
# author: suoxd123@126.com
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        cnt, rmIdx = n, m
        circle = [k for k in range(0,cnt)]
        for i in range(1,n):
            rmIdx = rmIdx%cnt - 1 #索引从0开始，计数从1开始
            tmpVal = circle.pop(rmIdx)
            cnt -= 1
            rmIdx = rmIdx + m if rmIdx >= 0 else m #索引为-1时，直接赋值m
        return circle.pop()
```

***
## 解法二（递归）
思路：使用逆向思考，本次操作是基于上一次操作结束后剩余的数据，反过来，本次操作删除的元素x，如果重新加入数组中，即为上一次删除剩余元素，因此可以考虑使用递归的方式，终点为数组为空，则返回0。
* 时间复杂度：O(n)
* 空间复杂度：O(1)
```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        if n == 0:
            return 0
        x = self.lastRemaining(n-1,m)
        return (m + x) % n
```

***
## 解法三（循环）
思路：将递归的思路，使用循环实现

* 时间复杂度：O(n)
* 空间复杂度：O(1)，另外也减少了栈空间的申请
```python
# author: suoxd123@126.com
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        last = 0
        for i in range(1,n):
            last = (last + m) % (i + 1)
        return last
```

***

欢迎大佬们，随手关注VX公众号【[真相很简单](https://www.zhenxiangsimple.com/categories/tech/math/)】，拍砖指导，查看一题多解

![zhenxiangSimple](https://pic.leetcode-cn.com/f5cdcda21a37ab2959ff8c7fa75e174b326a0b126a27296ba28e906b7309dab1-zhenxiangSimple.jpg)