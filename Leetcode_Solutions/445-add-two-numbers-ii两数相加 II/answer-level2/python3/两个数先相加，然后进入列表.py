class ListNode(object):
     def __init__(self, x):
         self.val = x
         self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        def get_list(head):
            res = []
            if head == None:
                return
            while head:
                res.append(head.val)
                head = head.next
            return res

        list1 = get_list(l1)
        list2 = get_list(l2)
        # nums = [1, 2, 3, 4]
        ss1 = [str(i) for i in list1]
        number1 = "".join(ss1)
        ss2 = [str(j) for j in list2]
        number2 = "".join(ss2)
        result = int(number1) + int(number2)
        print(result)

        ss = str(result)
        list_result = [int(i) for i in ss]
        new_list = ListNode(0)
        pre = new_list
        for i in list_result:
            node = ListNode(i)
            pre.next = node
            pre = pre.next
        return new_list.next


if __name__ == '__main__':

    def getNewList(list):
        if list:
            node = ListNode(list.pop(0))  # 初始化
            node.next = getNewList(list) # 一直遍历
            return node

    list1 = [7,2,4,3]
    list2 = [5,6,4]
    l1 = getNewList(list1)   # 链表
    l2 = getNewList(list2)
    s = Solution()
    print(s.addTwoNumbers(l1,l2))