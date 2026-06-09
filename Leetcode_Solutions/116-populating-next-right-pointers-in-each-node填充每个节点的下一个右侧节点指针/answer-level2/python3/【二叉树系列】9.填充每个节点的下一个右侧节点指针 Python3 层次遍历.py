

### 1.心中有树

看到这幅图，其实它给的提示很明显，**每个节点的下一个右侧节点**也就是层次遍历的变形，只是这次我们不需要每次保存每层节点的值，而是将它们顺序的设置为前一个节点的next节点

![image.png](https://pic.leetcode-cn.com/7609fb94dc4d220e8a4a85583147803c596d26f2f9d040ad5930f21264ca7acb-image.png)


先写一个层次遍历的大概模板吧：

[二叉树的层次遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-xi-lie-4er-cha-shu-de-ceng-ci-bian-li-p/)

然后进行一番修改：

```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return
        
        queue = [root]  # 依然是借助队列
        
        while queue:
            nxt = []  # 保存下一行的node
            
            for i in range(len(queue)-1):
                queue[i].next = queue[i+1]  # 依次赋next节点
                
            # queue[len(queue)-1].next = None
            
            for i in queue:  # 保存下一层节点
                if i.left:
                    nxt.append(i.left)
                if i.right:
                    nxt.append(i.right)
                    
            queue = nxt  # 更新队列queue
            
        return root
```


![image.png](https://pic.leetcode-cn.com/6b414208eea15c19c3864c009a45a9382647bbe755152558475d087a04bbd959-image.png)



>

> 今天我被c++折磨，还是python让我快乐~~~
> 但是这些题目前都不是难以理解，但是还是坚持写下去吧，等第一轮遍历结束的时候，之后可以边写边修改题解