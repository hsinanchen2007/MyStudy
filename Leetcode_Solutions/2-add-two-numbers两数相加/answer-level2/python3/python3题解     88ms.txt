先获取l1的值（int类型，需要将其转换为字符串），将其进行拼接，l2类同。将两个拼接后的字符串逆序后
相加求和，再将 和 转换为字符串，并使用切片逆序后存入链表

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        str1 = ""
        str2 = ""
        while l1:
            str1 += str(l1.val)
            l1 = l1.next

        while l2:
            str2 += str(l2.val)
            l2 = l2.next
        
        sum = int(str1[::-1]) + int(str2[::-1])
        sum_str = str(sum)

        # 指向同一存储域
        node = temp_node = ListNode(None)

        for x in sum_str[::-1]:
            if temp_node.val == None:
                temp_node.val = x
            else:    
                temp_node.next = ListNode(x)
                temp_node = temp_node.next

        return node