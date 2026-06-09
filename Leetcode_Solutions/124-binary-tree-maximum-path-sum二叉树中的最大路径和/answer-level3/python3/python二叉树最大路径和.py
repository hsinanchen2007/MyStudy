公众号：数学算法实验室

![2222.png](https://pic.leetcode-cn.com/11d3087d8ef3f8a49b471823f83db561f61deea06fcb59f572dc7fb3e4c8f45c-2222.png)


```
class Solution:
    """
    递归+贪心
    """
    def maxPathSum(self, root: TreeNode) -> int:
        global v 
        v=[]
        v.append(self.find(root))
        return max(v)
    def find(self , t):
        key2,key3= 0,0
        global v
        if t.left == None and t.right ==None:
            v.append(t.val)
            return t.val
        if t.left : key2 = self.find(t.left)
        if t.right : key3 = self.find(t.right)
        key1=t.val    
        key = max(key1, max((key1 + key2), (key1 + key3)))
        v.append(max(key,key1 + key2 + key3))
        return key
```

    