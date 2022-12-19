### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0a21927d2ac5d7825f495d40d745bf9e608c578ba3cd40d4fa0d937df9dfe5b5-image.png)
作为新手，刷题不多，粗浅地做个总结吧。

一看题目便联想到反转链表那题，对于这种不改变链表结构，即非合并or拆解，思路上应该往多指针方面靠，利用指针保存节点信息。
反转链表那题用了三个指针，那么这题就用相同思路去不断模拟，增加，删除。
链表题还有一个技巧就是添加一个头节点，应对一般情况，防止头节点信息丢失。

画图模拟是最好理解的，把自己ide，一步一步调试  =。=
### 代码

```python3
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or head.next:
            return head
        retHead = ListNode(0)
        preHead = retHead
        preHead.next = head

        curHead = preHead.next
        while curHead:
            if not curHead.next:
                return retHead.next
            rHead = curHead.next
            last = rHead.next
            preHead.next = rHead
            rHead.next = curHead
            curHead.next = last
            preHead = curHead
            curHead = preHead.next
        return retHead.next
```