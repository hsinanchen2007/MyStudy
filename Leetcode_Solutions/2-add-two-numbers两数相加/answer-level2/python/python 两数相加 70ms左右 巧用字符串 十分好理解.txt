### 解题思路
递归解法
构造了俩函数用字符串做中介 十分好理解

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def ln2str(ln):
            if ln.next == None:
                return str(ln.val)
            else:
                return str(ln.val)+str(ln2str(ln.next))

        def str2ln(str_res):
            if len(str_res)==1:
                return ListNode(int(str_res))
            else:
                ln_temp = ListNode(int(str_res[0]))
                ln_temp.next = str2ln(str_res[1:])
                return ln_temp
        
        str1 = ln2str(l1)[::-1]
        str2 = ln2str(l2)[::-1]
        str_res = str(int(str1)+int(str2))[::-1]
        return str2ln(str_res)




```