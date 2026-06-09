### 1.哈希表(字典)
![image.png](https://pic.leetcode-cn.com/ecc68352d01701ddf03704fb5513b15a3264817e9b680409a42591cb0ada3955-image.png)

- 从头遍历链表,将遍历到的元素放入字典里,如果有环的情况下那么必然会重复出现在哈希表;如果没有环,那么指针移动到最后就退出

### 代码
```
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        dic = {}
        while head:
            if head in dic:
                return True
            else:
                dic[head] = 1
            head = head.next
        return False
```


### 2.快慢指针的爱情💑
![image.png](https://pic.leetcode-cn.com/c8af8853f9c25e5309bdebd11bdc15074b111300434a5a3651840ccb0c5f489d-image.png)

- 想想你和你的girlfriend在操场跑步(圆环),你是个爷们必然会跑的快一些,你的脑海中总是浮现出她那甜蜜的微笑,因为你跑的快所以在某个瞬间你定会从后面将她拥入怀里!(有环,两人会在某一刻,也许是心动,就会遇见)
- 假如你们在直线(无环)上跑步,那么我相信善良你的也会在终点,饱含微笑等待她的到来,最终两人在终点相遇(没有环,两人便在链表尾相遇)
- 这里你每次跑两步,你的宝贝每次每次跑一步
- 最后祝福作为程序员的你能拥抱完美的爱情!! **生活微苦,爱情略甜**

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        
        if not head:
            return False
        temp1 = head.next
        if not temp1:
            return False
        temp2 = temp1.next
        
        while head and temp2:
            if head == temp2:
                return True
            head = head.next
            if temp2.next:
                temp2 = temp2.next.next
            else:
                return False
        return False
```