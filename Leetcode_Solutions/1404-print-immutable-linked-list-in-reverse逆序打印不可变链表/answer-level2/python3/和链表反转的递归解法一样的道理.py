对当前节点的下一个节点进行递归，直到当前递归的节点为空
相当于先在主函数中用栈把每个节点的执行情况都保存起来，
return之后，再按照出栈顺序依次执行剩下的命令，即print命令
实现逆序执行的效果

![image.png](https://pic.leetcode-cn.com/39912487952d811f287f1689c0a1a8d84b5000234f1baef2d182749bb1a68c75-image.png)



```
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
      if not head: return
      self.printLinkedListInReverse(head.getNext())
      head.printValue()
```
