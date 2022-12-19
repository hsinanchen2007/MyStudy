和环形链表一一样。无非两种方法，快慢指针或者用set。

快慢指针当他们两相遇的点并不一定就是环的点，需要点数学技巧求，还需要后移多少个点。我比较懒。嘻嘻

set方法如下：
```
class Solution(object):
    def detectCycle(self, head):
        set1=set([])
        while head not in set1:
            set1.add(head)
            if not head:
                break
            head=head.next
        return head
```

