    整体思路就是先把已有的值都取出来，然后去除重复，得到目标链表的值再新建链表即可，因为Python语言特性可以保证这个思路不需要太费脑子，不用思考如何迭代修改指针等等，直接走流程就好，详细如下。
    先把链表里面所有的值取出来放到一个栈里面，这里我们利用Python当中列表（List）的特性把元素挨个append进去就行，这样做的另外一个好处就是放入列表的顺序和原链表的顺序是完全对应的，非常方便；至于去除重复的过程还是利用Python当中非常方便的collections.Counter模块，输出列表里面每一个元素出现的次数，挨个pop出元素到一个新列表里面，这个新列表就是去除重复之后的新链表的全部值，Counter模块也是顺序对应的，因此只用append和pop方法得到的目标链表的值就是我们希望得到的顺序，不需要修改；最后根据目标链表的值新建一个链表即可，代码如下：
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        val, uni, p = [], [], head
        while p:
            val.append(p.val);p = p.next
        for i, j in collections.Counter(val).items():
            if j == 1: uni.append(i)
        temp = ListNode(0)
        curr, uni = temp, uni[::-1]
        while uni:
            curr.next = ListNode(uni.pop())
            curr = curr.next
        return temp.next    
