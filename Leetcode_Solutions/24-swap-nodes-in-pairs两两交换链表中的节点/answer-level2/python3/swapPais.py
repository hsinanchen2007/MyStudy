```python
    def swapPairs(self, head: ListNode) -> ListNode:
        print(self) 
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            pre.next, b.next, a.next = b, a, b.next
            pre = a
            print("pre:",pre.val)
        return self.next
```

pre, pre.next = self, head self变量用作哨兵指向单项链表的前一个节点.   pre, a, b是三个指针变量
pre, pre.next = self, head 
```
初始状态
1->2->3

self->1->2-3             //pre,pre.next=self,head
pre                      //pre在self下面代码指针变量pre指向self

self ->2 ->1 ->3            //pre.next,b.next,a.next=b,a,b.next
pre    b   a 

self ->2  ->1   ->3       //pre=a
       b    pre
```        
还需要注意的是python的连续变量赋值
a=3
a,b=1,a
结果a=1,b=3

