方法1：无需手写进制转换，且内存100%

先遍历整个链表输出字符串
字符串用int转换为十进制

class Solution:
    def getDecimalValue(self, head):
        s=0
        while head :
            s =str(str(s)+str(head.val))
            #print(head.val)
            head=head.next
        return int(s,base=2)