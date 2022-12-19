### 方法一、解题思路
用字典存层。

### 代码
```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        d = collections.defaultdict(list)
        def f(r, i):
            if r:
                d[i].append(r.val)
                f(r.left, i + 1)
                f(r.right, i + 1)
        f(root, 0)
        return d.values()
```

### 方法二、解题思路
迭代器生成。

### 代码

```python []
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        d = [root] if root else []
        while d:
            yield [t.val for t in d]
            d = [r for t in d for r in (t.left, t.right) if r] 
```
![image.png](https://pic.leetcode-cn.com/e360621e7b6de86d9039561b7e58ba739e621f6272ca8b5c4255a5128124fab7-image.png)
