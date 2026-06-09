### 解题思路
磕磕绊绊写了一个最原始的解法（O(n*n)时间复杂度），给需要的朋友参考。
之前一直纠结为什么要原始链表中记录 randomNode 的位置，想的是直接通过 random指向 得到节点就可以了，然后在复制链表中从头到尾找到与randomNode的val一样的值进行指向就可以了。
但是仅仅通过val是无法定位 randomNode 节点的（如果多个节点的val相同怎么办），所以还是得通过位置在定位。


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        print(head == head)

        # 复制next指针
        copyList = Node(-1)
        copy_curr = copyList
        org_curr = head
        while(org_curr):
            val = org_curr.val
            node = Node(val)
            org_curr =  org_curr.next
            copy_curr.next = node
            copy_curr = copy_curr.next

        # 复制random指针
        org_curr = head
        copy_curr = copyList.next
        while(org_curr and copy_curr):
            print(org_curr.val,copy_curr.val)
            if org_curr.random == None:
                copy_curr.random = None
            else:
                randomNode = org_curr.random # 获取 randomNode
                # 记录randomNode在原始链表中的位置
                tmp_curr = head
                cnt = 1
                while(tmp_curr):
                    if tmp_curr == randomNode:
                        break
                    else:
                        tmp_curr = tmp_curr.next
                        cnt += 1
                
                # 在复制链表中 从头到尾找到 randomNode，并进行指向
                tmp_curr = copyList
                while(cnt>0):
                    tmp_curr = tmp_curr.next
                    cnt -= 1
                copy_curr.random = tmp_curr

            # 原始链表和复制链表 同时往下走一步
            org_curr = org_curr.next
            copy_curr = copy_curr.next     

        return copyList.next
```