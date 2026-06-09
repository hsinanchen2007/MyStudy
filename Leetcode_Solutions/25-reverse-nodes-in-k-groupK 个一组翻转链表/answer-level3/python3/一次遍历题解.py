# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        # 新的ListNode的开头
        newb = ListNode(0)
        # 新的ListNode的结尾
        newe = newb
        # 存储节点
        temp = []
        # 判断存储的节点个数
        flag = 0
        while True:
            
            # 截取k个节点
            if head != None and flag < k:
                flag += 1
                temp.append(head)
                head = head.next
            
            # 如果节点总数不是 k 的整数倍，将最后剩余的节点保持原有顺序。
            elif head == None and flag < k:
                if temp == []:
                    break
                else:
                    newe.next = temp[0]
                    break
                    
            # 进行节点交换
            else:
                newe.next = temp[-1]
                x = head
                for i in range(k-1, 0, -1):
                    temp[i].next = temp[i-1]
                temp[0].next = x
                
                # 为下一次循环做初始化和设置, head不用next
                flag = 0
                newe = temp[0]
                
                temp = []
                    
        return newb.next