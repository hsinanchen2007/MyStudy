### 解题思路
![image.png](https://pic.leetcode-cn.com/b12eaf177df02d6ffbde03b0837a75ce1304b272fbca2df98069899243147d6e-image.png)
- 我们知道两个链表如果有重复的节点,则从第一个重复节点之后就都相同了,对于这个题有三种解法
- 先假设我们有两个链表`headA`和`headB`.`m`,`n`为链表长度
1. 使用暴力法
- 这个很简单,在第一个链表`headA`上遍历每个节点,每遍历到一个节点时,就对`headB`整个遍历一遍,直到出现相同的节点为止.
- 时间复杂度`O(m*n)`,空间复杂度为`O(1)`

2. 使用双栈法
- 这个方法的思路是,我们需要两个栈来保存两个链表,由于栈的特性,保存完之后,栈顶元素是链表的最后一个元素.
- 我们知道如果存在重复的节点,那么这两个栈中的上面几个元素是相同的
- 同时从两个栈顶弹出元素,直到弹出的两个元素不相等时,那么前一个元素就是我们要找的重复节点
- 时间复杂度`O(m+n)`,空间复杂度`O(m+n)`,用空间换取时间

3. 单遍历法
- 我们想下如果给我们的两个数组长度相等,那么我们是不是就能同时遍历两个数组,看遍历到哪个节点的时候相等即可了
- 例如给定`1,4,6,3,5,7,8`和`1,8,5,4,5,7,8`,这两个长度相等,同时遍历,当遍历到`5`时,我们就找到了第一个重复的节点
- 根据上面的思路我们需要先把两个链表弄成等长的,也就是先遍历两个链表的长度,存储下来`m`和`n`
- 假设`m > n`,那么就在长度为`m`的链表上先遍历`m-n`个节点,这样就使得两个链表符合了上面的条件
- 时间复杂度`O(m+n)`,空间复杂度`O(1)`

4. 关于代码部分,我只写了第三种方法,仅供参考
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        len_A = 0
        len_B = 0
        temp_A = headA
        temp_B = headB
        while headA:
            len_A += 1
            headA = headA.next
        while headB:
            len_B += 1
            headB = headB.next
        if len_A > len_B:
            headA = temp_A
            headB = temp_B
            for i in range(len_A - len_B):
                headA = headA.next
            while headA != headB and headA:
                headA = headA.next
                headB = headB.next
        else:
            headA = temp_A
            headB = temp_B
            for i in range(len_B - len_A):
                headB = headB.next
            while headA != headB and headA:
                headA = headA.next
                headB = headB.next
        if not headA:
            return None
        else:
            return headA

            
        
            
```