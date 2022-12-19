打卡第二天
```
class Solution(object):
    def reverseList(self, head):
        # p 做原表的遍历，q 做返回的新链表
        p , q = head , None
        while p !=None :
            q , q.next , p = p , q , p.next

        return q;
```

