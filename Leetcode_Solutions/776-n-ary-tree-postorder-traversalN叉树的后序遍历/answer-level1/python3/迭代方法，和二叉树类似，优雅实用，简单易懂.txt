使用递归太没有技术含量。
这里的方法借鉴了二叉树后续遍历的方法，
在pre节点的寻找上，利用了children中对象的唯一性，使用python列表的index函数来寻找下一个child。

![image.png](https://pic.leetcode-cn.com/af202083e30fe1270afda351daaabba6619e07b17e1f73cf4614a37128190ecd-image.png)


```
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
      if not root: return []
      res =[]
      pre = None
      stack = []
      self.dfs(root, stack, res, pre)
      return res
      
    def dfs(self, curr, stack, res, pre):
      while curr or len(stack) > 0:
        while curr:
          stack.append(curr)
          if len(curr.children) > 0:
            curr = curr.children[0]
          else: curr = None
        curr = stack[-1]
        if len(curr.children) == 0 or pre == curr.children[-1]:
          curr = stack.pop()
          res.append(curr.val)
          pre = curr
          curr = None
        else:
          curr = curr.children[curr.children.index(pre) + 1]
      return res
```
