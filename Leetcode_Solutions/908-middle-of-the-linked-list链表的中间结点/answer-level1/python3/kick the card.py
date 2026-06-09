### 解题思路
punch in the card. 

Again, I will give you the code. 

### 代码

```python3

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        a=head
        b=head
        while b!=None:
            b=b.next
            if b==None:
                break
            else:
                b=b.next
            a=a.next
        return a

```