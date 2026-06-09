```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        #k个链表当前的节点进行插入排序
        if len(lists)==0:
            return None
        
        #将列表中的空链表pop
        index = 0
        while index<len(lists):
            if lists[index]==None:
                k = lists.pop(index)
            else:
                index+=1
        
        #每次循环都将列表中所有元素的值比较,找到值最小的,其节点作为当前节点,连接到最终的链表上,再将列表中对应的最小值的节点next,如果是          #None,直接pop,否则将列表中的该节点替换
        head = ListNode(9999)
        head.next = None
        t = head
        while len(lists)>0:
            index = 0
            min_value = 9999
            for i,j in enumerate(lists):
                if j!=None and j.val<min_value:
                    index = i
                    min_value = j.val
            t.next = lists[index]
            t = t.next
            if lists[index].next!=None:
                lists[index] = lists[index].next
            else:
                k = lists.pop(index)
        return head.next
            
            
            
        
```
