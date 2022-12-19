### 方法1

先求两个链表的长度，然后在让相对长的链表走到跟短链表相同长度的位置，然后再一起遍历，找到相等（位置，地址都相等，这里是个坑）的位置，返回。若没有找到，返回None。时间复杂度O(n), 空间复杂度O(l)，但是好像空间用的挺多，不知道为啥~

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA==None or headB==None:
            return None
        p = headA
        count1 = 0
        while p:
            count1 += 1
            p = p.next
            
        q = headB
        count2 = 0
        while q:
            count2 += 1
            q = q.next
        
        if count1<count2:
            headA, headB = headB, headA 
            count1, count2 = count2,count1
            
        while count1>count2:
            headA = headA.next
            count1 -= 1
        
        while headA:
            
            if headA==headB:
                return headA
            else:
                headA, headB = headA.next,headB.next
        return None
            
            
```

### 方法2

方法2参考评论。通过巧妙的方法，使两个链表到达相等位置时走过的是相同的距离。时间复杂度还行，空间复杂度不知道为啥又很一般


![微信图片_20190531161836.jpg](https://pic.leetcode-cn.com/3aa8a5100e239cf1f63f2990b24d2eabbc8c40c58cc8a57e8c33a214d92d3022-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190531161836.jpg)

链表1的长度是x1+y，链表2的长度是x2+y，我们同时遍历链表1和链表2，到达末尾时，再指向另一个链表。则当两链表走到相等的位置时：
                                      
  `x1+y+x2 = x2+y+x1`

没交点则y=0, 结尾都指向None。代码如下：

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        p,q = headA,headB
        while p!=q:
            p = p.next if p else headB
            q = q.next if q else headA
        return p
            
```

### 方法三

思路很简单，就是用数组存储起来，然后再逆序找，代码如下：

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if headA == None or headB == None:
            return None
        p = []
        q = []
        while headA:
            p.append(headA)
            headA = headA.next
        while headB:
            q.append(headB)
            headB = headB.next
        count = -1
        target = None
        l1 = len(p)
        l2 = len(q)
        while -count<=l1 and -count<=l2:
            if q[count] == p[count]:
                target = p[count]
                count -= 1
            else:
                break
        return target
```

