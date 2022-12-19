```
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        sumlist, nodelist, sum = list(), list(), 0
        newhead = ListNode(0)
        newhead.next = head
        node = newhead
        while node:
            sum += node.val
            if sum in sumlist:
                while sum in sumlist:
                    s = sumlist.pop()
                    n = nodelist.pop()
                n.next = node.next
                sumlist.append(s)
                nodelist.append(n)
                sum = sumlist[-1] if sumlist else 0
            else:
                sumlist.append(sum)
                nodelist.append(node)
            node = node.next
        return newhead.next
```
