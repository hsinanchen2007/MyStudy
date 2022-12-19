除了链表为空，其实链表就分为两种情况
奇数个和偶数个
例如 1 2 3 4 5 null  
第一次迭代 1->3
          2->4
第二次迭代
          3->5
          4->null
可以以偶部游标是否为None:作为终止条件

当个数为偶数个，例如 1 2 3 4 5 6 
第二次迭代
        3->5
        4->6
        进入循环体后，原本更改指向的地方就会报错（由于next.next）直接捕获该错退出循环即可
```
class Solution(object):
    def oddEvenList(self, head):
        if head is None:
            return head
        else:
            pre = head #奇数游标
            last = head.next#偶数游标
            tmp = head.next #偶数首地址
            while  last:
                try:
                    pre.next = pre.next.next#1-3 3-5
                    last.next = last.next.next#2-4 4-null
                except:
                    break
                pre = pre.next#3
                last = last.next#4
            pre.next = tmp
            return head
```
