```
class ListNode:
    def __init__(self, x):
        self.val = x       #数据域
        self.next = None   #指针域

class Solution:
    #解法1：采用栈结构，将链表的元素依次压入栈中。然后依次将栈中的元素弹出，后入先出，反转链表
    def reverseList(self, head ) :
        poit = head  #初始化poit 指向头结点head
        linlist = [] #初始化[],用于存放链表数值
        #遍历单表
        while poit:
            linlist.insert(0, poit.val)
            poit = poit.next

        poit = head # poit 重新指向head
        #然后重组单链表
        for i in range(len(linlist)):
            poit.val = linlist[i]  #开始依次赋值
            poit = poit.next       #poit依次后移
        return head #最后返回头节点head

    #解法2：采用“头插法”， 依次拿下链表的节点，在头部插入，从而形成逆向链表
    def reverseList2(self, head):
        #判断当前链表状态
        if head == None  : #当链表为空
            return head    #直接返回

        if head.next == None: #当链表只有一个节点
            return head       #则也直接返回当前节点

        #否则当链表长度大于2，即需要逆转时
        p = head         # 获得头结点位置,用来遍历原始链表
        head = None      # 释放head，用于头插法生成新链表
        while p:
            cur = p               #获得当前节点
            p = p.next         #临时头指针 p 后移
            cur.next = head   #断开cur ,并插入 head前面
            head = cur        # head指针 前移
        return head #返回头节点

    #解法3：递归  没有头结点，head直接指向链表中的第一个节点
    def reverseList3(self, head):
        #判断当前链表状态
        if head == None  : #当链表为空
            return head    #直接返回

        if head.next == None: #当链表只有一个节点
            return head       #则也直接返回当前节点

        p = self.reverseList3(head.next)
        head.next.next= head
        head.next = None
        return p
```
