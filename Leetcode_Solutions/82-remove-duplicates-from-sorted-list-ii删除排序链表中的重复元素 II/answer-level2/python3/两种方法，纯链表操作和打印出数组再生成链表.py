![image.png](https://pic.leetcode-cn.com/6394120727a0ab307a69c43235ee1789f99786f2cd2d39b0234525add4c8e6d8-image.png)

纯链表操作一次遍历就解决了，而且不用复制数组，所以比较快，但实际空间并不小，关键就是要记录父指针，相当于是双指针，然后遇到又重复的时候就把父指针pre指向下一个不重复的点。

```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head:
            ans=ListNode(0)
            ans.next=head
            pre=ans
            while head and head.next:
                if head.next.val==head.val:
                    while head.next:
                        if head.next.val==head.val:
                            head.next=head.next.next
                        else:
                            break
                    pre.next=head.next
                else:
                    pre=pre.next
                head=head.next
            return ans.next
```

![image.png](https://pic.leetcode-cn.com/cc0e3f975a245afc22057e9ad9163be01b1207bab339372535a362abfefd4283-image.png)

用字典统计链表值的数量，把数量为1的放进数组，然后生成链表，这个比较好理解。但实际上有三次循环，所以相对较慢，但循环都比较简单，所以也不是慢到不可接受的地步。

```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        d=collections.defaultdict(int)
        while head:
            d[head.val]+=1
            head=head.next
        a=[i for i in d if d[i]==1]
        n=len(a)
        if n>0:
            h=ListNode(a[0])
            ans=h
            for i in range(1,n):
                h.next=ListNode(a[i])
                h=h.next
            return ans
```
