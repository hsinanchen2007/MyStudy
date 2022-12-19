
时间复杂度 O(n)
空间复杂度 O(1)
```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        #: 思路：分成三部分[1,m),[m,n],(n,len(list)]
        #: 把第一部分的末端接到[n]，然后[m]接到第三部分
        
        #：找出第一部分[1,m)
        part1_start = head
        part1_end = head
        node = head
        i = 1
        while i<m:
            i += 1
            part1_end = node
            node = node.next
        #: 找出第二部分[m,n]，并把这第二部分反转
        part2_start = node
        next_node = node
        pre = None
        while i <= n:
            i += 1
            next_node = node.next
            node.next = pre
            pre = node
            node = next_node
        part2_end = pre
        #： 找到第三部分的起点
        part3_start = node
        #: 重新连接
        if part1_end == part2_start:
            head = part2_end
        else:
            part1_end.next = part2_end
        part2_start.next = part3_start

        return head



```
