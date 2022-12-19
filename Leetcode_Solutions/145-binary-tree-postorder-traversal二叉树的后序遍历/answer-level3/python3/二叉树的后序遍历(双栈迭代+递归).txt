
## 双栈迭代

后序遍历是在前序遍历的基础上做的，前序遍历的压栈顺序为：根、左、右，后续遍历为左、右、根。一个简单的思想是使用两个栈，一个压入的顺序是先左后右，从第一个栈弹出再压入第二个栈的时候就是先右后左了，并且此时根节点最先压入，打印的时候就会是左、右、根了。

```python []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        s1, s2, res = [], [], []
        p = root
        s1.append(p)
        while s1:
            p = s1.pop()
            s2.append(p)
            if p.left: s1.append(p.left)
            if p.right: s1.append(p.right)
        while s2:
            p = s2.pop()
            res.append(p.val)
        return res
```

```C++ []
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();
        vector<int> res;
        stack <TreeNode*> s1;
        stack <TreeNode*> s2;
        TreeNode* p = root;
        s1.push(p);
        while (!s1.empty()){
            p = s1.top();
            s1.pop();
            s2.push(p);
            if (p->left) s1.push(p->left);
            if (p->right) s1.push(p->right);
        }
        while (!s2.empty()){
            p = s2.top();
            s2.pop();
            res.push_back(p->val);
        }
        return res;
    }
};
```

## 递归

递归思路就比较简单了，res填加val的位置决定了遍历的类型，放在最前面是前序遍历，放在中间是中序遍历，放在最后是后序遍历

```python []
class Solution:
    def posorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root: return []
        self.posOrder(root, res)
        return res

    def posOrder(self, root, res):
        if root:
            ##res.append(root.val) ##放在这里是前序遍历
            self.posOrder(root.left, res)
            res.append(root.val) 放在这里是中序遍历
            self.posOrder(root.right, res)
            ## res.append(root.val) 放在这里是后序遍历
        return res
```

```C++ []
class Solution {
public:
    vector<int> posorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root== NULL) return vector<int>();
        posOrderRecur(root, res);
        return res;

    }
    
    void posOrderRecur(TreeNode* root, vector<int> &res){
        if (root){
            //res.push_back(root->val); //放在这里是前序遍历
            posOrderRecur(root->left, res);
            //res.push_back(root->val); 放在这里是中序遍历
            posOrderRecur(root->right, res); 
            res.push_back(root->val); 放在这里是后序遍历      
        }
    }
};
```
