主要思路就是引入了辅助字符串
再利用[::-1]得到反转字符串
其他的操作并不算难
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a=b=''
        while l1 :
            a+=str(l1.val)
            l1=l1.next
        c=a[::-1]
        while l2 :
            b+=str(l2.val)
            l2=l2.next
        d=b[::-1]
        v=int(c)+int(d)
        v=str(v)
        # 在此之前返回一个整数和也就是v即可
        cc=pre=ListNode(0)
        for j in range(len(v)):
            tools=ListNode(int(v[len(v)-1-j]))
            pre.next=tools
            pre=pre.next
        return cc.next