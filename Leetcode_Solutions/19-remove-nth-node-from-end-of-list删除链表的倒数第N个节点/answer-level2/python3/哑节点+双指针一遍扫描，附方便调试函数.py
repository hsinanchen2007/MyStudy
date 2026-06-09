### 解题思路
利用哑节点便于删除第一个点，用双指针实现直扫描一遍。
两个间距为n+1的指针同时右移，右面一个到链表结尾时，前面一个刚好到倒数第n+1个点，下一个即时要删除的节点。

### 代码

```python3
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node = ListNode(0) # 哑节点
        node.next = head   
        
        l = 0
        lp = node   # 左指针
        rp = node   # 右指针
        while rp:
            if l <= n:
                rp = rp.next    # 移动直至左右间距 n+1 个指针， 右指针rp到None时，左指针指向倒数第n个节点
            else:
                lp = lp.next
                rp = rp.next
            l += 1

        lp.next = lp.next.next    # 跳过要删除的节点
        
        return node.next
```

对于这种链表的题，有时本地调试不方便，所以写了两个简单的函数方便调试。
```python3
def make_listnode(arr):  # 把list列表转换成链表
    res = ListNode(0)
    res2 = res
    for a in arr:
        node = ListNode(a)
        res.next = node
        res = res.next
    return res2.next

def show_listnode(head): # 打印链表，以 list 形式显示
    res = []
    while head:
        res.append(head.val)
        head = head.next
    print(res)

'''
e.g.
arr = [1,2,3,4,5]
listnode = make_listnode(arr)  # list 变成 nodelist
print(show_listnode(listnode)) # nodelist 再变回 list, 所以又输出[1,2,3,4,5]
'''
```