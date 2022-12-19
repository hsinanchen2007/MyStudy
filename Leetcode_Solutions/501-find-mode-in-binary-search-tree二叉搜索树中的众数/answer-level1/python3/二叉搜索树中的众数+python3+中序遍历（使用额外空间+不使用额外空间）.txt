### 1.使用额外空间的中序遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

 对于二叉搜索树来说，中序遍历就是一个升序数组，可以基于该数组判断众数。代码如下：
```
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = self.order(root)
        n = len(ans)
        target = [0,0] 
        m=0
        count =1 
        while m<n-1:
            if ans[m]==ans[m+1]:
                m +=1
                count+=1
            else:
                if count>target[0]:
                    target = [count,ans[m]]
                elif count==target[0]:
                    target.append(ans[m])    
                
                count = 1
                m += 1
        if count>target[0]:
            target = [count,ans[m]]
        elif count==target[0]:
            target.append(ans[m])    
        return target[1:]
        
        
    def order(self,root):
        if not root:
            return []
        return self.order(root.left)+[root.val]+self.order(root.right)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)
### 2.不使用额外空间
题目要求不使用额外空间，改了一下代码。略啰嗦：
```

class Solution:
    def __init__(self):
        self.count = 1
        self.target = [0,0]
        self.pre = -1            # 初始判断值设为-1，用于判断第一个值（中序遍历，即最左边的值）
        
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        self.inorder(root)
        
        #最后一组数在递归终止后无法判断，因此要重新判断一下
        if self.count >self.target[0]:
            self.target = [self.count,self.pre]
        elif self.count==self.target[0]:
            self.target.append(self.pre)
        return self.target[1:]
    
    # 中序遍历，边遍历边判断
    def inorder(self,root):
        if not root:
            return None
        self.inorder(root.left)
        if root:
            if self.pre == -1:                 #第一个值，其实相当于初始化pre值                        
                self.pre = root.val
            elif self.pre == root.val:
                self.count += 1
            else:
                if self.count >self.target[0]:
                    self.target = [self.count,self.pre]
                elif self.count==self.target[0]:
                    self.target.append(self.pre)
                self.count = 1
                self.pre = root.val
        self.inorder(root.right)
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)，递归的空间O(n),target数组的空间最多也到O(n)