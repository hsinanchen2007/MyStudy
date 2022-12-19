一 二叉树的层次遍历
```python3 []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        layer = []
        de = collections.deque()
        if root is not None:
            de.append(root)
            end = root
        while de:
            p = de.popleft()
            layer.append(p.val)
            if p.left:
                de.append(p.left)
            if p.right:
                de.append(p.right)
            if p == end:
                res.append(layer[:])
                layer.clear()
                if de:
                    end = de[-1]
        return res
```
二 二叉树的层次遍历II
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        layer = []
        de = collections.deque()
        if root is not None:
            de.append(root)
            end = root
        while de:
            p = de.popleft()
            layer.append(p.val)
            if p.left:
                de.append(p.left)
            if p.right:
                de.append(p.right)
            if p == end:
                res.append(layer[:])
                layer.clear()
                if de:
                    end = de[-1]
        res.reverse()
        return res
```
三 二叉树的层平均值
```
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        #res = []
        # layer = []
        # de = collections.deque()
        # if root is not None:
        #     de.append(root)
        #     end = root
        # while de:
        #     p = de.popleft()
        #     layer.append(p.val)
        #     if p.left:
        #         de.append(p.left)
        #     if p.right:
        #         de.append(p.right)
        #     if p == end:
        #         res.append(sum(layer) / len(layer))
        #         layer.clear()
        #         if de:
        #             end = de[-1]
        # return res
        
        res = []
        de = collections.deque()
        if root is not None:
            de.append(root)
            end = root
        length = 0
        total_num = 0
        while de:
            p = de.popleft()
            total_num += p.val
            length += 1
            if p.left:
                de.append(p.left)
            if p.right:
                de.append(p.right)
            if p == end:
                res.append(total_num / length)
                total_num = 0
                length = 0
                if de:
                    end = de[-1]
        return res
```
四 二叉树的锯齿形层次遍历
```
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:        
        # res = []
        # layer = []
        # de = collections.deque()
        # if root is not None:
        #     de.append(root)
        #     end = root
        # while de:
        #     p = de.popleft()
        #     layer.append(p.val)
        #     if p.left is not None:
        #         de.append(p.left)
        #     if p.right is not None:
        #         de.append(p.right)
        #     if p == end:
        #         res.append(layer[:])
        #         layer.clear()
        #         if de:
        #             end = de[-1]
        # for lst in res[1::2]:
        #     lst.reverse()
        # return res
```
五 在每个树行中找最大值
```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []
        layer = []
        de = collections.deque()
        if root is not None:
            de.append(root)
            end = root
        while de:
            p = de.popleft()
            layer.append(p.val)
            if p.left:
                de.append(p.left)
            if p.right:
                de.append(p.right)
            if p == end:
                res.append(max(layer))
                layer.clear()
                if de:
                    end = de[-1]
        return res
```


