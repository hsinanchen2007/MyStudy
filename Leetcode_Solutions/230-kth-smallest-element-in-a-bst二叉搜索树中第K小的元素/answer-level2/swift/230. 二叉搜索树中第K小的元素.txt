# **思想 与 解法**
## 1. 二分法
### 思想
二叉搜索树特点是左节点值小于根节点，而右节点值大于根节点；利用这个特性可以采用二分法，将整个树的节点分为左节点和右节点两部分，当k值等于左节点值+1时，说明此时root为要求的第k小元素；当k值小于左节点值时，说明第k小元素位于根节点左侧；当k值大于左节点时，说明第k小元素位于根节点右侧；之后递归，在满足条件的左右两侧节点中进行遍历划分，直到求出第k小。
### 代码
```
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int){
        self.val = val
        self.left = nil
        self.right = nil
    }
}

func kthSmallest(_ root: TreeNode?, _ k: Int) -> Int {
    let left_num = calculate(root?.left)
    if k - 1 == left_num {
        return root?.val ?? 0
    } else if k - 1 < left_num {
        return kthSmallest(root?.left, k)
    } else {
        return kthSmallest(root?.right, k - 1 - left_num)
    }
}

func calculate(_ root: TreeNode?) -> Int {
    if root == nil {
        return 0
    }
    let num = 1 + calculate(root?.left) + calculate(root?.right)
    return num
}
```

## 2.中序排序(递归)
### 思想
二叉搜索树特点是左节点值小于根节点，而右节点值大于根节点；当我们进行中序遍历时【左中右】，就可以将整个二叉搜索树按照从小到大的顺序进行遍历，使用一个计数器，当与k值相等时，就可以输出当前节点元素。
### 代码
```
public:
    int kthSmallest(TreeNode* root, int k) { //利用中序遍历进行计数
        int num = 0;
        int res = 0;
        Inorder(root,k,num,res);
        return res;
    }//中序遍历(左中右)
    void Inorder(TreeNode* root,int k,int &num,int &res){
        if(root == NULL)
        {
            return ;
        }
        Inorder(root->left,k,num,res);
        num++;
        if(k == num)
        {
            res = root->val;
        }
        Inorder(root->right,k,num,res);
    }
```

## 2.中序排序(栈)
### 思想
原理同样是中序遍历，但是结合了栈进行了操作，降低了递归引起的效率低的问题
### 代码
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        while (1)
        {
            if (root)
            {
                s.push(root);
                root = root->left;
                continue;
            }
            if (k == 1)
                return s.top()->val;
            root = s.top()->right;
            s.pop();
            k--;
        }
    }
};
```
