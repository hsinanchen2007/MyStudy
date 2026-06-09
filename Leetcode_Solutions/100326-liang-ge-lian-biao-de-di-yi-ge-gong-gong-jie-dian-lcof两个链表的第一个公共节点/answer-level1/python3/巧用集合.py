先遍历A链表把所有节点都放入集合，然后遍历B，当发现集合长度不增长，说明刚才扔进去得节点是重复节点。
![微信图片_20200403224131.png](https://pic.leetcode-cn.com/6c2b05e4aa31080088cef3db5bb5b4ba48c23001a4a50d0ccaf9186d03dc4988-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200403224131.png)


```
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        s = set()
        while headA:
            s.add(headA)
            headA = headA.next
        l = len(s)
        while headB:
            s.add(headB)
            if len(s)==l: return headB
            else: l+=1
            headB = headB.next
        return None
```
