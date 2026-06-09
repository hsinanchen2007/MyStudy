新人，一开始对输入链表数据结构这点表述有点奇怪，看到测试的输入为[2,4,3]，这样的格式，我以为输入的是列表，然后再创建单项链表，再进行运算。阅读水平真差
看了大佬的写法，也慢慢的理解了。「有个疑问是链表的输出表现形式是列表的样子的？？？？还望大佬指点」
主要思路就是，先将链表转化为列表，再将列表的元素转化为字符串并进行翻转相加，最后将得到的结果转化为链表的形式输出。

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        #将链表转化为列表的形式
        list1 = []
        list2 = []
        while l1:
            list1.append(l1.val) #l1就是一个游标
            l1 = l1.next
        while l2:
            list2.append(l2.val) #l1就是一个游标
            l2 = l2.next
            
        #将列表的元素转化为字符串并进行翻转想加
        turn_list1 = [str(list1[len(list1) - 1 - i]) for i in range(len(list1))]   #翻转并转化为字符串
        turn_list2 = [str(list2[len(list2) - 1 - i]) for i in range(len(list2))]
        turn2int1 = int(''.join(turn_list1)) 
        turn2int2 = int(''.join(turn_list2))
        my_sum = turn2int1 + turn2int2    #得到相加后的结果
        
        #将得到的结果转化为链表的形式
        sum_list = list(str(my_sum))
        turn_sum_list = [int(sum_list[len(sum_list) - 1 - i]) for i in range(len(sum_list))]    #翻转、转化为int型数据
        node = ListNode(turn_sum_list[0])    #node就相当于是head
        cur = node
        for i in turn_sum_list[1:]:
            cur.next = ListNode(i)
            cur = cur.next
        
        return node
```
