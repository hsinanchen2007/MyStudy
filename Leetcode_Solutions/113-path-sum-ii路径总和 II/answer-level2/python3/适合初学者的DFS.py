可以看到，树的dfs和图的有点区别，树不需要申请额外空间去记录每个节点是否被访问过，但是图是需要的，道理应该很容易想

下面代码是一种思路，两种写法，有个小trick是  每次传入 sum-root.val 

还有就是python里面list是引用传递，所以最后要pop()

感叹下自己以前是最熟悉C++和java的，现在却变成了无能的炼丹师，掉包侠
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        def find(root,sum,temp=[]):
            if not root:return
            temp.append(root.val)
            if not root.left and not root.right:
                if sum-root.val==0:
                    res.append(temp[:])
            if root.left:
                find(root.left,sum-root.val,temp)
                temp.pop()
            if root.right:
                find(root.right,sum-root.val,temp)
                temp.pop()

        find(root,sum,[])
        return res
```
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res = []
        def find(root,sum_,temp=[]):
            if not root:return
            temp.append(root.val)
            if not root.left and not root.right:
                if sum_+root.val== sum:
                    res.append(temp[:])
            if root.left:
                find(root.left,sum_+root.val,temp)
                temp.pop()
            if root.right:
                find(root.right,sum_+root.val,temp)
                temp.pop()
        find(root,0,[])
        return res
```
