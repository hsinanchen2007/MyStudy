### 解题思路
可以使用hashmap和双指针法求解，思路与官方题解一致，给出python版本

### 方法一
使用hashmap
### 代码

```python3

class Solution47:
    #若是有环，则存在循环，使得i。next=j.next,j-i即为循环的长度，
    def hasCycle(self, head):
        if head is None:
            return False
        res=False
        l=[]
        r=head
        while r.next is not None:
            if r in l:
                res=True
                break
            else:
                l.append(r)
                r=r.next
        return res
```
### 方法二
使用快慢两个指针

### 代码

```python3
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head is None:
            return False
        res=False
        slow=head
        quick=head.next
        while slow.next is not None:
            if slow==quick:
                res=True
                break
            elif quick.next is None or quick.next.next is None:  #快指针已经走到尽头
                break
            else:
                quick= quick.next.next   #快指针走两步
                slow=slow.next         #慢指针走一步
        
        return res
```