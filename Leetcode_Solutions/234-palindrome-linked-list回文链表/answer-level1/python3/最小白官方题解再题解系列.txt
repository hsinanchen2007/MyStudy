```
'''
LeetCode 234. 回文链表
Given a singly linked list, determine if it is a palindrome.
Example 1:
Input: 1->2
Output: false
Example 2:
Input: 1->2->2->1
Output: true

题目大意：
请判断一个链表是否为回文链表。
示例 1:
输入: 1->2
输出: false
示例 2:
输入: 1->2->2->1
输出: true

解题思路：
这道题比较简单，我给你写三种方法，务必掌握，我们一点点加难度，重点是快慢指针法，前面反转链表是这道题的前置题目
方法1：将值复制到数组中后用双指针法
如果你还不太熟悉链表，下面有列表的概要。
有两种常用的列表实现，一种是数组列表和链表。如果我们想在列表中存储值，那么它们是如何保存的呢？这个我面试被问过好几次！！！！！！！！
1，数组列表底层是使用数组存储值，我们可以通过索引在 O(1)的时间访问列表任何位置的值，这是由于内存寻址的方式。
2，链表存储的是称为节点的对象，每个节点保存一个值和指向下一个节点的指针。访问某个特定索引的节点需要 O(n)的时间，
因为要通过指针获取到下一个位置的节点。
因此最简单的方法就是将链表的值复制到数组列表中，再判断。
算法：
1，复制链表值到数组列表中。
2，使用双指针法判断是否为回文。
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        vals = []
        current_node = head
        while current_node is not None:
            vals.append(current_node.val)
            current_node = current_node.next
        return vals == vals[::-1]
方法2：递归
递归你也应该理解了，递归是利用栈，先不断计算到最下面，然后再往上面返回答案
也即，递归包含反转到思想在里面，我们也可以利用递归进行回文判断（你是不是可以实现一个列表的回文递归判断）
核心思想是，通过一个正向的头节点，一个是递归反向返回的当前节点进行val对比，就知道是不是回文了
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        self.front_pointer = head # 这个是正向的头节点
        def recursively_check(current_node=head): # 递归函数，传入当前节点，返回判断到当前节点是不是回文，是返回true继续递归
            if current_node is not None: # 没递归完，也是递归跳出条件
                if not recursively_check(current_node.next): # 不是回文，返回false了
                    return False
                if self.front_pointer.val != current_node.val: # 正向的值和反转的值不相等，返回返回false
                    return False
                self.front_pointer = self.front_pointer.next # 正向前移
            return True # 否则判断到当前就是回文
        return recursively_check()
方法3：快慢指针
先利用快慢指针找到中点，然后反转后半部分，与前面一一对比
'''
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 快慢指针法，快指针走两步，慢指针走一步，找到链表的中点。然后，翻转后半部分。最后从头、中点开始判断是否相同。
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        slow = head
        fast = head
        reverse_head = None
        # 找到链表的中点，链表长度奇偶不影响
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # 将slow之后链表进行断开且反转，最后翻转完成之后reverse_head指向反转链表的头节点,也就是最后一个节点
        while slow: # 迭代反转链表，参考leetcode206，一模一样
            tmp = slow.next
            slow.next = reverse_head
            reverse_head = slow
            slow = tmp
        # 前后链表进行比较，注意若为奇数链表，后半部分回比前部分多1一个节点，然而我们只比较相同长度的节点值，巧妙地避开这点判断
        #printList(head)
        #printList(reverse_head) # 参照我这样打印就可以了，调试注意别改变指针，会影响最终结果
        while head and reverse_head: # 只比较相同长度的节点值
            if head.val != reverse_head.val:
                return False
            head = head.next
            reverse_head = reverse_head.next
        return True

def generateList(l: list) -> ListNode: #这是为了打印结果，写的生成链表的函数，传入列表list即可
    prenode = ListNode(0) #哑节点
    lastnode = prenode
    for val in l: #遍历传入的列表
        lastnode.next = ListNode(val) #不断创建新节点，并链接
        lastnode = lastnode.next #指针后移，不移动的话就是还在原位置后面创新新节点了
    return prenode.next # 别把哑巴节点返回了啊

def printList(l: ListNode):  #打印链表函数，传入的是链表哦
    while l:
        print("%d" %(l.val), end = '->')
        l = l.next
    print('NULL')

if __name__ == "__main__":
    # e.g. 1->2->2->1
    l1 = generateList([1,2,2,1])
    printList(l1)
    s = Solution()
    print(s.isPalindrome(l1))
```
