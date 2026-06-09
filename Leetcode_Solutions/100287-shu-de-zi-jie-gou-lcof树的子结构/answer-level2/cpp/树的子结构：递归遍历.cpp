思路：
1. 首先要遍历A找出与B根节点一样值的节点R
2. 然后判断树A中以R为根节点的子树是否包含和B一样的结构

```c++ []
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;
        //当TreeA和TreeB都不为零的时候，才进行比较。否则直接返回false
        if (A!=NULL && B!=NULL)
        {
            //如果找到了对应TreeB的根节点的点
            if (A->val == B->val)
                //以这个根节点为为起点判断是否包含TreeB
                res = helper(A, B);
            //如果找不到，那么就再去TreeA的左子树当作起点，去判断是否包含TreeB
            if (!res)
                res = isSubStructure(A->left, B);
            //如果还找不到，那么就再去TreeA的右子树当作起点，去判断是否包含TreeB
            if (!res)
                res = isSubStructure(A->right, B);
        }
        // 返回结果
        return res;
    }

    bool helper(TreeNode* A, TreeNode* B)
    {
        //如果TreeB已经遍历完了都能对应的上，返回true
        if (B==NULL)
            return true;
        //如果TreeB还没有遍历完，TreeA却遍历完了。返回false
        if (A==NULL)
            return false;
        //如果其中有一个点没有对应上，返回false
        if (A->val != B->val)
            return false;
        //如果根节点对应的上，那么就分别去子节点里面匹配
        return helper(A->left, B->left) && helper(A->right, B->right);
    }
};
```
```python3 []
class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        res = False
        if A is not None and B is not None:
            if A.val == B.val:
                res = self.helper(A,B)
            if not res:
                res = self.isSubStructure(A.left, B)
            if not res:
                res = self.isSubStructure(A.right, B)
        return res
    
    def helper(self, A, B):
        if B is None:
            return True
        if A is None:
            return False
        if A.val != B.val:
            return False
        return self.helper(A.left, B.left) and self.helper(A.right, B.right)
```
[更多剑指offer题解（C++与Python实现）](https://github.com/bryceustc/CodingInterviews)

[更多LeetCode题解（C++与Python实现）](https://github.com/bryceustc/LeetCode_Note)

