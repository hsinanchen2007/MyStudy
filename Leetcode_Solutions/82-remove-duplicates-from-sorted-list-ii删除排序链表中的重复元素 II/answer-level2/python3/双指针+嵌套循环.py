```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        '''
        记住，尤其特别多边界条件的时候，先不去考虑边界条件，把整体思路的框架先写好，然后再去
        把边界条件考虑周全，一开始就考虑完全边界条件是很困难的一件事！！！
        思路：
        双指针+两次试探（即嵌套两个循环）来保证 left.val 和 right.val 是不重复的！
        具体：
        step1：先考察left指针，保证 left.val 是不重复。然后去考察right指针
        step2：保证right.val 是不重复。然后再让 left 和 right 移动。
        '''
        left = head
        if head == None:
            # 空链表
            return head
        right =head.next        
        while right != None:
            # step1:考察left指针
            # flag1标记用于记录left.val是否重复了，一旦重复了的情况出现，flag1 = 0
            flag1 = 1
            # 当重复的情况出现时，用两个循序进行考察，因为：
            # 例如：1>1>1>2>2>3>4>5，两个嵌套循环可以保证left指针指向3那个位置！
            while right != None and left.val == right.val:
                # 在最外层做一个预先判断
                # 外层循环能保证找到left.val=3, right.val=4这样的结果
                while right != None and left.val == right.val:
                    # 内层循环消除值重复，保证找到right.val != left.val ,例如1 != 2
                    right = right.next
                # 指针前移，让外层循环做一个预判断
                if right != None:
                    # 从内层循环出来的right一定是和left的值是不同的。left的值因为有重复，所
                    # 以直接不要。我们让left前移到right，right移向right.next
                    # 然后让最外层循环做一个预判断，如何指针前移后值仍然相等，
                    # 就继续到内层循环消除值重复的情况。
                    left = right
                    right = right.next
                else:
                    # right == None, 是边界判断。
                    left = None
                flag1 = 0
            # step1 出来之后可以保证left.val是不会有重复值的，这里要注意，head指针的修改！
            if flag1 == 0:
                head = left
            # step2:考察right指针。
            # 这里要注意，从step1 出来之后，left，right == None 和left和right指针正好是最后
            # 两个结点时，就不需要考察right指针了。
            flag2 = 1
            # 同step1一样，外层循环预判断，内层循环+条件判断消除重复
            while right != None and right.next != None and right.val == right.next.val:
                while right.next != None and right.val == right.next.val:
                    right = right.next
                right = right.next
                flag2 = 0
            if left == None:
                return left
            elif flag2 == 1 and right != None:    
                left = left.next
                right = right.next
            elif right == None:
                left.next = right
            else:
                left.next = right
                left = right
                right = right.next
        return head
```
