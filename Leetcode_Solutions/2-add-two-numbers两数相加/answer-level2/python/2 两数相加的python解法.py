### 解题思路1
该思路是每次重新生成一个ListNode，会比较占用内存空间。

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
        l3 = ListNode(0) if  (l1!=None or  l2!=None) else None
        l_init = l3
        carry_val = 0
        while(l1!=None or  l2!=None):
            left_val = ((l1.val if l1 else 0) + (l2.val if l2 else 0) + l3.val) % 10
            carry_val = ((l1.val if l1 else 0) + (l2.val if l2 else 0) + l3.val) / 10
            print l1.val if l1 else 0, l2.val if l2 else 0, left_val, carry_val   

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

            l3.val = left_val
            if carry_val == 0 and (l1!=None or  l2!=None):
                l3.next = ListNode(0)
                l3 = l3.next
            # elif carry_val == 1 and (l1!=None or  l2!=None):
            elif carry_val == 1:
                l3.next = ListNode(carry_val)
                l3 = l3.next

        return l_init


        
```



### 解题思路2
不用生成一个新的节点，直接将两个节点相加的值赋给节点l3就可以了。


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

        l1_init = l1
        l2_init = l2
        l3 = None
        l3_init = l3
        carry_val = 0
        
        while(l1_init!=None or  l2_init!=None):
            left_val = ((l1_init.val if l1_init else 0) + (l2_init.val if l2_init else 0) + carry_val) % 10
            carry_val = ((l1_init.val if l1_init else 0) + (l2_init.val if l2_init else 0) + carry_val) / 10
            print l1_init.val if l1_init else 0, l2_init.val if l2_init else 0, left_val, carry_val   

            l3, l3.val = l1_init if l1_init else l2_init, left_val
            l1_init = l1_init.next if l1_init else None
            l2_init = l2_init.next if l2_init else None
            l3.next = l1_init if l1_init else l2_init

        if carry_val == 1:
            l3.next = ListNode(carry_val)

        return l1

```


### 解题思路3
用递归的思路解答，这里暂时pending，后面解答。


### 代码
```python
```