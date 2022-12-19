## 前序遍历

任何算法的递归版本都可以改成非递归版本，因为函数递归调用其实质就是压栈的过程，那么我们完全可以使用栈来模拟这个过程

前序遍历主要借助栈来实现，是中左右的过程，首先压入根结点，此时栈不为空，进入循环。然后弹出当前结点，弹出的时候打印结点。如果右孩子存在，右孩子压入栈内。如果左孩子存在，左孩子压入栈内。先右后左依次压栈，弹出的时候就会是先左后右打印，对于每个结点循环这个过程就实现的前序遍历。

```python []
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:return []
        stack, res = [], []
        p = root
        while stack or p:
            while p:
                stack.append(p)
                res.append(p.val)
                p = p.left
            p = stack.pop()
            p = p.right      
        return res
```
```C++ []
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return vector <int> ();
        stack <TreeNode*> s;
        TreeNode* p = root;
        vector<int> res;
        while (!s.empty() || p){
            while (p){
                s.push(p);
                res.push_back(p->val);
                p = p->left;
            }
            p = s.top();
            s.pop();
            p = p->right;
        }
        return res;
    }
};
```

## 递归

递归思路就比较简单了，res填加val的位置决定了遍历的类型，放在最前面是前序遍历，放在中间是中序遍历，放在最后是后序遍历

```python []
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root: return []
        self.preOrder(root, res)
        return res

    def preOrder(self, root, res):
        if root:
            res.append(root.val) ##放在这里是前序遍历
            self.preOrder(root.left, res)
            ## res.append(root.val) 放在这里是中序遍历
            self.preOrder(root.right, res)
            ## res.append(root.val) 放在这里是后序遍历
        return res
```
```C++ []
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root== NULL) return vector<int>();
        preOrderRecur(root, res);
        return res;

    }
    
    void preOrderRecur(TreeNode* root, vector<int> &res){
        if (root){
            res.push_back(root->val); //放在这里是前序遍历
            preOrderRecur(root->left, res);
            //res.push_back(root->val); 放在这里是中序遍历
            preOrderRecur(root->right, res); 
            //res.push_back(root->val); 放在这里是后序遍历      
        }
    }
};
```