## 中序遍历（迭代）

中序时，我们首先去遍历整个二叉树的左分支，并依次将节点压入栈中，直到找到最左边的叶节点，然后弹出并打印，并看其有没右分支；如果没有，返回上一级并弹出当前根节点，然后看其有没有右分支。每次弹出，都要观察其是否有右分支，也就是说每个节点都遍历了两次！（整个过程先处理整个树的左边界，然后处理右树的左边界）

```python []
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        stack, res = [], []
        p = root
        while (stack or p):
            if p:
                stack.append(p)
                p = p.left
            else:
                p = stack.pop()
                res.append(p.val)
                p = p.right
        return res
```
```C++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();
        stack <TreeNode*>s;
        vector<int> res;
        TreeNode* p = root;
        while (!s.empty() || p){
            if (p) {
                s.push (p);
                p = p->left;
            }
            else {
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};
```

## 递归

递归思路就比较简单了，res填加val的位置决定了遍历的类型，放在最前面是前序遍历，放在中间是中序遍历，放在最后是后序遍历

```python []
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root: return []
        self.inOrder(root, res)
        return res

    def inOrder(self, root, res):
        if root:
            ##res.append(root.val) ##放在这里是前序遍历
            self.inOrder(root.left, res)
            res.append(root.val) 放在这里是中序遍历
            self.inOrder(root.right, res)
            ## res.append(root.val) 放在这里是后序遍历
        return res
```
```C++ []
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root== NULL) return vector<int>();
        inOrderRecur(root, res);
        return res;

    }
    
    void inOrderRecur(TreeNode* root, vector<int> &res){
        if (root){
            //res.push_back(root->val); //放在这里是前序遍历
            inOrderRecur(root->left, res);
            res.push_back(root->val); 放在这里是中序遍历
            inOrderRecur(root->right, res); 
            //res.push_back(root->val); 放在这里是后序遍历      
        }
    }
};
```