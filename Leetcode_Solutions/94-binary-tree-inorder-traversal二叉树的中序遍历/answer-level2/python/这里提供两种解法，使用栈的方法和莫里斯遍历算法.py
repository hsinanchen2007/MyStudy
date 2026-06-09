使用栈辅助的算法：
思路：使用栈来协助，思想是把节点放到栈里去，由栈来控制节点的输出顺序，我的思想一个节点先push进去，如果有左节点则继续push左节点，一直到没有左节点，然后pop出一个节点，并指向它右节点进行新一轮push判断，如果是空则再pop直到队列为空且没有其它节点了，仔细想想这个过程其实就是左中右的顺序
```
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret_list = []
        stack = []
        while root or len(stack) > 0:
            while root:
                stack.append(root)
                root = root.left
            
            tmp = stack.pop(-1)
            ret_list.append(tmp.val)
            root = tmp.right
        return ret_list
```


莫里斯中序遍历算法：
思路：
它的思想是把它变成一个线索二叉树，如下：
![1.PNG](https://pic.leetcode-cn.com/e7f8031dfc361a9a5eb74f57957b9b3c10610ce1ddc09cd75f1e6f683cf7a130-1.PNG)


变化算法：
（1）把1置为cur，如果cur有左孩子，则左孩子置为pre，所以2置为pre，然后寻找2的最右节点，比如2个最右节点是5，则pre为5，然后用pre的右孩子指向cur，接着cur被置为2，又开始一轮，就是4指向2，接着cur是4，这时cur没有左孩子了，直接添加到输出列表，且将cur = cur.right，可以看到这时其实是开始回溯了
（2）按（1）这样可以看到其实是有环路的，所以程序里我们会用环路来判断当前是不是出于回溯状态，然后根据这个条件将之前增加的指向（比如之前的5的右孩子指针指向1）置回去，这样便不改变原有树的结构了
以下再给个图，以方便看到这里回溯的思想：

![1.PNG](https://pic.leetcode-cn.com/c57d692d455caf85a1b8a7c866a5f6f941ab04363f194030c97b042b3c9328ac-1.PNG)


这里是1,2,3,5,6,7,8为例，可以看到当遍历到5时，利用之前构建的环又回到了2，7回到了6，8回到了1

```
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret_list = []
        cur = root
        while cur:
            if cur.left is None:
                ret_list.append(cur.val)
                cur = cur.right
            else:
                pre = cur.left
                while pre.right is not None and pre.right is not cur:
                    pre = pre.right
                if pre.right is None:
                    pre.right = cur
                    cur = cur.left
                else:
                    ret_list.append(cur.val)
                    pre.right = None
                    cur = cur.right
        return ret_list
```

