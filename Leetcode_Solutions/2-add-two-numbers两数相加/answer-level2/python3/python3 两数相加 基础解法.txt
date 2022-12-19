```
# 定义单项链表
# ListNode:模仿官方定义，以便在编译器可以运行
class ListNode:
    def __init__(self, x):
        # 将传入参数转换成单链表形式
        # 第一种情况:参数是单数
        if isinstance(x,int):
            self.val = x
            self.next = None
        # 第二种情况:参数>=10
        elif isinstance(x,list):
            self.val = x[0]
            self.next = None
            for i in x[1:]:
                self.next = ListNode(i)
                self = self.next
# 只需提交Solution类这个code
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 将传入的参数(默认用列表),转换成单链表,在提交code的时候不用处理这步(题目系统默认给链表数据)
        if isinstance(l1,list):
            l1 = ListNode(l1)
        if isinstance(l2,list):
            l2 = ListNode(l2)
        # 定义一个存储结果的新链表,令第一个节点为0(这个是个开始节点,之后计算得到的结果从第二个节点开始存储)
        nList = ListNode(0)
        newlist = nList
        # 定义进位(0或1),默认0
        carry = 0
        while(l1 or l2):
            # 分别存储链表l1、l2的值，这里是三木运算符操作(若l1当前节点的值存在，x为l1当前节点值,否则为0)
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            # 1.计算两链表节点对应位数相加的值
            # 2.并存入新节点
            # 3.判断是否有进位
            single = x + y + carry
            newlist.next = ListNode(single % 10)
            carry = single // 10
            # 一轮完事儿之后,继续寻找指向两链表当前节点的下一个节点
            if l1!=None:l1 = l1.next
            if l2!=None:l2 = l2.next
            # 指向当前存储的节点
            newlist = newlist.next
        # 判断是否还有进位(例如：8->9(第一组数) + 2(第二组数) = 0->0->1)
        if carry == 1:
            newlist.next = ListNode(1)
        # 返回以第二个节点为开头的链表
        return nList.next
# 测试数据
if __name__ == "__main__":
    test = Solution()
    print(test.addTwoNumbers([2,4,3],[5,6,4]))

```
