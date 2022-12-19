
## 思路
如果不记录最大值，就是一个比较标准的二叉树遍历。而要求输出每一层的最大值的话，就需要遍历到某一层的时候记录下当前层的最大值。

步骤：
1. 遍历二叉树
2. 每到一层的时候比较下是不是当前层的最大值。这里我是通过传递层号来记录当前走到哪里的。


## 解法
``` python
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:

        max_val_dict = {}

        def helper(root, idx):
            if not root:
                return
            
            val = root.val 
            if idx in max_val_dict:
                max_val_dict[idx] = max(max_val_dict[idx], val)
            else:
                max_val_dict[idx] = val
            
            helper(root.left, idx + 1)
            helper(root.right, idx + 1)
        
        helper(root, 0)
        idx = 0
        res_list = []
        while idx in max_val_dict:
            res_list.append(max_val_dict[idx])
            idx += 1
        return res_list
```

## 优化
我这里用字典记录最值，后面按照顺序输出的时候还得走一遍遍历。实际上用个数组就可以，能更高效一些，感兴趣的同学可以试下。
