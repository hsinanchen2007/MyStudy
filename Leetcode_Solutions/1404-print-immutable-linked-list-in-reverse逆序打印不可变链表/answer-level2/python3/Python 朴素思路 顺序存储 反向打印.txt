![image.png](https://pic.leetcode-cn.com/49280106d87906f993d16408c78e9c945321d54ed4690f257e2d15d76450a0ca-image.png)


```
'''
顺序存储 反向打印
'''
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        nodes = []
        cur = head
        while cur is not None:
            nodes.append(cur)
            cur = cur.getNext()

        for node in reversed(nodes):
            node.printValue()
```
