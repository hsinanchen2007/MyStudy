### 解题思路
不需要判断两部分，主要判断右子树。

### 代码

```python3
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        if not postorder:return True
        root=postorder[-1]
        # 寻找左子树
        cur_index=0
        for i in range(len(postorder)):
            if postorder[i]>=root:
                cur_index=i
                break
        left = postorder[:cur_index]
        right=postorder[cur_index:-1]
        for num in right:
            if num<root:
                return False
        return self.verifyPostorder(left) and self.verifyPostorder(right)
                
        
```