### 解题思路
此处撰写解题思路

### 代码

```python3
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def reverseBetween(self,head,m,n):
        #边界情况的考虑:结点为空或者只有1个结点
        if not head or not head.next:
            return head
        #当链表结点数量大于2个，但是m,n相等时
        if m==n:
            return head
        #设置头结点，方便统一处理
        h=ListNode("Headnode")
        h.next=head
        #########使用双指针定位反转链表范围#########
        fw,bw=h,h
        count=0
        #先移动bw指针，使得fw和bw之间的差为n-m
        while count!=n-m:
            count+=1
            bw=bw.next
        #将两个指针定位到具体的链表位置
        step=m-1
        while step:
            step-=1
            fw=fw.next
            bw=bw.next
        #fw定位在指定位置的前1个位置
        bw=bw.next
        #逆转指定范围的链表
        wp=fw.next
        epoch=n-m
        while epoch:
            epoch-=1
            fw.next=wp.next
            wp.next=bw.next
            bw.next=wp
            wp=fw.next
        return h.next

```