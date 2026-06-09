(⊙﹏⊙)手贱把之前那个题解删掉了...心在滴血

#### 请先看一下代码
```python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head

        l1 = head.next
        head.next = self.swapPairs(head.next.next)
        l1.next = head

        return l1
```

#### gif 的注意事项：
1. 留意背景中的第 x 轮，它指示了递归调用的深度
2. 当程序执行到哪一步时，对应的语句将变红显示
![6.gif](https://pic.leetcode-cn.com/f98018f19db0751d5c7fb6aa4abbf37a45da6b1dfccb111d9c9c94f24508cd41-6.gif){:width=500}
{:align=center}


#### 详细说明
#### 0. 第0轮
`head=[1,2,3,4,5,6,7]`，`head.next=[2,3,4,5,6,7]`，`head.next.next=[3,4,5,6,7]` 传入第1轮递归。
![image.png](https://pic.leetcode-cn.com/1d86b4115d7e17288a54e34d2bd4da1b7f8be002bf9f69c20457578d6919e687-image.png){:width=500}
{:align=center}


#### 1. 第1轮
`head=[3,4,5,6,7]`，`head.next=[4,5,6,7]`，`head.next.next=[5,6,7]`传入第 2 轮递归。
![image.png](https://pic.leetcode-cn.com/8a5189deb8fbb7c0c26ac8855d216974a4a85372eb74f00ce8e10575a08d62fa-image.png){:width=500}
{:align=center}


#### 2. 第2轮
`head=[5,6,7]`，`head.next=[6,7]`，`head.next.next=[7]`传入第 3 轮递归。
![image.png](https://pic.leetcode-cn.com/333cc9d9153653866e8f2581a1e9a0a1e0780b8adbef69799e0b21763e3d3bfc-image.png){:width=500}
{:align=center}


#### 3. 第3轮
`head=[7]`，`head.next=none`，返回 `head=[7]`，回到第 2 轮递归。
![image.png](https://pic.leetcode-cn.com/5611fbf5b2de6344206db3b92beb00c80bc8a162f36420bb83ac0ffe11abc9b9-image.png){:width=500}
{:align=center}


#### 4. 第2轮
`head=[5,7]`，返回 `res=[6,5,7]`，回到第 1 轮递归。
![image.png](https://pic.leetcode-cn.com/950c63d4a000a65201439eadacd9e9f670194e0e92b39e801a50234166c0a675-image.png){:width=500}
{:align=center}


#### 5. 第1轮
`head=[3,6,5,7]`，返回`res=[4,3,6,5,7]`，回到第0轮递归。
![image.png](https://pic.leetcode-cn.com/ca246c0ec1064030092d21375432196d8e5799885fd769392f47cf8a4aa1f4f9-image.png){:width=500}
{:align=center}


#### 6. 第0轮
`head=[1,4,3,6,5,7]`，返回`res=[2,1,4,3,6,5,7]`，结束递归。
![image.png](https://pic.leetcode-cn.com/6a87eedbf5d93098480dbbe22f4b5f4147117a7cfaee93f29338405050c8d43d-image.png){:width=500}
{:align=center}

