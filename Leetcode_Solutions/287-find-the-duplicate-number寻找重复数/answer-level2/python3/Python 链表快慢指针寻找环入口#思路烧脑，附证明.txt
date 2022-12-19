### 解题思路

看了评论介绍，可以将这个题目变成寻找环入口的题目，那为什么快慢指针可以寻找到环入口呢？

首先想象一个链表有一个环（本文所有配图盗自 https://blog.csdn.net/donghuaan/article/details/78988987）

![e00ade282ebb478a9b6404b66f40d060_SouthEast.png](https://pic.leetcode-cn.com/1164f7ea6401621f2929cfcff0bf2e732e3da2049ddfcc01b4fa6c6b7dbd75a9-e00ade282ebb478a9b6404b66f40d060_SouthEast.png)

一个快指针（蓝色），一个慢指针（红色）

假设从链表头部到达环的入口需要走 k 步

![da48a05a9cfb298fc76dd0bf2fed78ac_SouthEast.png](https://pic.leetcode-cn.com/15625c1543fbb07b517482845498d7685eea85aae76e7bfd949568444bd3d789-da48a05a9cfb298fc76dd0bf2fed78ac_SouthEast.png)

慢指针走了 k 步

那么快指针就走了 2k 步，而且现在快指针已经可能在环里走了 x 圈（假设走一圈 R 步），并且现在离环入口 delta 步

可以得到
```
2k = k + xR + delta
```
左边表示快指针走了 2k 步，右边表示快指针先走了 k 步到达环入口，然后在环里转了 x 圈，再走了 delta 步

整理一下得到
```
等式一：k = xR + delta
```


然后快慢指针继续走着，终有一天两人相遇（为什么一定相遇？最后再提）

![fdc6ea843def1823e285209d37bda81f_SouthEast.png](https://pic.leetcode-cn.com/8fd27781359ebed16f038a4b04f6f5cd9d606db8282b390a8fa8ded712704574-fdc6ea843def1823e285209d37bda81f_SouthEast.png)

假设两人在距离入口 m 步的地方相遇了

那么慢指针走了 a 圈加 m 步（aR + m），快指针走了 2(aR + m) 步

对于快指针，相当于走了 b 圈加 m 步减去 delta 步（因为快指针一开始就在离入口 delta 步的地方）

可以得到
```
2(aR + m) = bR + m - delta
```

整理一下得到
```
等式二：m = yR - delta，其中 y = (b-2a)
```

将等式一二合并，得到
```
m + k = (x+y)R
```

意思是，他们现在正在离入口 m 步的地方，只要再走 k 步，就相当于从入口出发走了 x + y 圈，回到了入口

而 k 恰恰就是链表头离环入口的步数。

所以就让两个指针一个在环内继续走，一个去到链表头开始走，大家都一次走一步

当从链表头开始走的指针，走到环入口的时候，也就是走了 k 步的时候，

就能遇到在环内继续走，走了 k 步回到了入口的指针，而且相遇的地方就是环入口。


### 关于一开始快慢指针为什么一定会相遇

根据等式二，快慢指针一定相遇的条件是等式

```
2(aR + m) = bR + m - delta
```

对于任何 R 和 delta ，都存在 a, b, m 的正整数解

根据整理后的等式

```
m = (b-2a)R - delta
```

一定可以构造一组解，使得


```
m = R - delta
b - 2a = 1
```

成立，证明了快慢指针在环内一定会相遇


### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        fast = slow = 0
        while True:
            fast = nums[nums[fast]]
            slow = nums[slow]
            if fast == slow:
                fast = 0
                while fast != slow:
                    fast = nums[fast]
                    slow = nums[slow]
                return fast

```