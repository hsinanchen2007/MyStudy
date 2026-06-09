
### 方法一： 递归法

找到递归点：左树与右树对称与否，与其跟两树的子树的对称情况有关系。

递归结束条件：
- 都为空指针则返回 true
- 只有一个为空则返回 false
- 两个指针当前节点值不相等 返回false

递归过程：
- 判断 A 的右子树与 B 的左子树是否对称
- 判断 A 的左子树与 B 的右子树是否对称

```c++ []
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        if (root!=NULL)
        {
            res = helper(root->left,root->right);
        }
        return res;
    }

    bool helper(TreeNode*A, TreeNode* B)
    {
        // 先写递归终止条件
        if (A==NULL && B==NULL)
            return true;
        // 如果其中之一为空，也不是对称的
        if (A==NULL || B==NULL)
            return false;
        // 走到这里二者一定不为空
        if (A->val != B->val)
            return false;
        // 前序遍历
        return helper(A->left,B->right) && helper(A->right,B->left);
    }
};
```
```python []
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        res = True
        if root:
            res = self.helper(root.left, root.right)
        return res
    
    def helper(self,A,B):
        if A is None and B is None:
            return True
        if A is None or B is None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left,B.right) and self.helper(A.right,B.left)
```
#### 复杂度分析
- 时间复杂度：$O(n)$，因为我们遍历整个输入树一次，所以总的运行时间为$O(n)$，其中$n$是树中结点的总数。
- 空间复杂度：递归调用的次数受树的高度限制。在最糟糕情况下，树是线性的，其高度为$O(n)$。因此，在最糟糕的情况下，由栈上的递归调用造成的空间复杂度为$O(n)$。

### 方法二： 迭代法

利用队列进行迭代。队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像。最初，队列中包含的是 `root->left` 以及 `root->right`。该算法的工作原理类似于 BFS，但存在一些关键差异。每次提取两个结点并比较它们的值。然后，将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，或者检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。
```c++ []
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root ==NULL)
            return true;
        //用队列保存节点
        queue<TreeNode*> q;
        //将根节点的左右孩子放到队列中
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            //从队列中取出两个节点，再比较这两个节点
            TreeNode* A = q.front();
            q.pop();
            TreeNode* B = q.front();
            q.pop();
            //如果两个节点都为空就继续循环，两者有一个为空就返回false
            if (A==NULL && B==NULL)
                continue;
            if (A==NULL || B==NULL)
                return false;
            if (A->val != B->val)
                return false;
            //将左子树的左孩子， 右子树的右孩子放入队列
            q.push(A->left);
            q.push(B->right);
            //将左子树的右孩子，右子树的左孩子放入队列
            q.push(A->right);
            q.push(B->left);
        }
        return true;
    }
};
```
```python []
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        q = []
        q.append(root.left)
        q.append(root.right)
        while len(q)!=0:
            A = q.pop(0)
            B = q.pop(0)
            if A == None and B == None:
                continue
            if A == None or B == None:
                return False
            if A.val != B.val:
                return False
            q.append(A.left)
            q.append(B.right)
            q.append(A.right)
            q.append(B.left)
        return True 
```
#### 复杂度分析
- 时间复杂度：$O(n)$，因为我们遍历整个输入树一次，所以总的运行时间为$O(n)$，其中$n$是树中结点的总数。
- 空间复杂度：搜索队列需要额外的空间。在最糟糕情况下，我们不得不向队列中插入$O(n)$个结点。因此，空间复杂度为$O(n)$

#### [更多剑指Offer题解（C++与Python实现）](https://github.com/bryceustc/CodingInterviews)
#### [更多LeetCode题解（C++与Python实现）](https://github.com/bryceustc/LeetCode_Note)