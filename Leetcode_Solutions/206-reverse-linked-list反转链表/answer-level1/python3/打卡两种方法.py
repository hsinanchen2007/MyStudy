### 解题思路

### 方法1：迭代
迭代法是比较直接的，双指针配合，从head开始依次反转。注意反转前保留下head.next（当然python神奇的赋值操作就不需要这个额外变量了） 
循环进行以下操作，直至来到当前链表的末尾：
- 反转：head的下一个节点指向pre
- 移动：pre，head均往后移动一个节点
### 代码

```python3
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        #方法1：迭代
        pre=None #pre永远指向head的前一个结点
        while head:
            head.next,pre,head=pre,head,head.next
        return pre
```

### 方法2：递归
递归方法不如上一个好理解。递归类问题我觉得主要是找到递归结构和返回条件。
- 递归结构：把整个链表拆解成第一个节点和一条链表，链表反转可以递归调用本函数，那么这里只要考虑第一个节点怎么接上。
- 返回条件：每个链表都这么拆解，到最后没得拆了就要返回。
### 代码

```python3
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        #方法2：递归
        if head==None:return head #处理传入空链表的特殊情况
        if head.next==None:return head #递归何时返回
        p=self.reverseList(head.next) #获得尾部最后一个节点
        head.next.next=head #节点指向反转
        head.next=None #原来的指向要拆掉
        return p
```

--------------
大家的题解也很多了，简单记录一下自己的想法