```
'''
递归法：
递归问题的关键有二：
其一： 递归方程
其二：递归出口

这道题之所以可以使用递归，最关键的点在于如何处理递归出口，
当某一个list已经先遍历结束，而另一个却没有结束的时候。如果你选择分类讨论，那递归的出口将会非常的复杂。这就增加了递归的难度

可是如果我们可以通过补0的形式，把仅剩一个list的时候的问题，转换成两个list相加的问题，这就减少了大量分类讨论的难度。

具体如何实施补0的几乎呢？
1。 当一个是None的时候，就让其为0
2。当返回的时候，是None的，就继续让其是None。

list的关键问题：
无论是list还是tree，在遍历的过程中，你是没有办法返回的。因此这给函数之间的传递（传参的设置和函数返回提供了困难）

我们需要熟悉list的函数的流程
1. 传参：通常传参都是一个node，表示以该node为root的sublist or subtree.
2. return: 
            1）如果在调用函数之前，已经记录了head，那么函数通常不需要return
            2）如果调用之前没有记录head，那么你在被调用的函数的开头就要记录head，并在最后return该head
            
            简单说就是，如果在父函数中记录了head，就不需要return，否则就要在子函数中记录head并返回
        

'''



# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pre_node = ListNode(None)
        self.add(pre_node,l1,l2,0)
        return pre_node.next


    def add(self, pre_node, l1, l2, flag):

        if l1 is not None or l2 is not None:
            x = 0 if l1 is None else l1.val
            y = 0 if l2 is None else l2.val

            cur_node = ListNode((x + y + flag) % 10)
            flag = int((x + y + flag) / 10)

            pre_node.next = cur_node


            if l1 is None:
                return self.add(cur_node, None, l2.next, flag)
            elif l2 is None:
                return self.add(cur_node, l1.next, None, flag)
            else:
                return self.add(cur_node,l1.next,l2.next, flag)

        else:
            if flag == 1:
                new_node = ListNode(1)
                pre_node.next = new_node
            return






n1 = ListNode(2)
n2 = ListNode(4)
n3 = ListNode(3)
n1.next = n2
n2.next = n3

n4 = ListNode(5)
n5 = ListNode(6)
n6 = ListNode(4)
n4.next = n5
n5.next = n6


foo = Solution()
foo.addTwoNumbers(n1,n4)















```
