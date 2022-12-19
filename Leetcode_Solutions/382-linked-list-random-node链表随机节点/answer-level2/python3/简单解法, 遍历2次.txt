思路:
1. 先用一个游标遍历, 计算节点的总数count
2. 从[0, count)随机一个整数
3. 再遍历第二次, 产生出随机节点即可(注意取值范围)
```python
import random
class Solution:

    def __init__(self, head: ListNode):
        self.head = head
        

    def getRandom(self) -> int:
        count = 1
        cursor = self.head
        while cursor.next:
            cursor = cursor.next
            count += 1
            
        cursor = self.head
        randomer = random.randrange(count)
        for i in range(randomer):
            cursor =cursor.next
        return cursor.val
