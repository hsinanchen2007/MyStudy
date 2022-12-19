给出一种很容易理解的递归解法
由于操作可能会涉及两个父节点的子节点，无法通过一个参数递归完成，故需要借助`helper()`函数完成。
逐步分解任务可以发现，每一次连接操作都是在重复如下操作：
将右边节点连接到左边节点的next上。
根据分析，得出`helper(t1, t2)`定义为:连接t1->t2。
具体代码如下：
```python
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return None
        def helper(t1, t2):
            if t1 is None and t2 is None:
                return
            t1.next = t2
            return helper(t1.left, t1.right), helper(t1.right, t2.left), helper(t2.left, t2.right)
        helper(root.left, root.right)
        return root 
```
虽然该解法效率较低，但是是一种经典的递归解法。