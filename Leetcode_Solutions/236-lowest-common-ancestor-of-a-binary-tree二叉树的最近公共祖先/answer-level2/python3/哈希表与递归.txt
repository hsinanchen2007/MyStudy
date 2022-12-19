## 哈希表
采用哈希表的方法思路直观，但是代码较长
1.首先建立一个哈希表，保存每个结点的父节点，
2.然后遍历p结点的父节点，保存到一个set()集合。
3.遍历q结点的父节点，遇到的第一个相同的结点即为最近公共祖先。
```python []
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        dic = {root:None}
        self.dfs(root,dic)
        hash_set = set()
        l1, l2 = p, q
        while l1:
            hash_set.add(l1)
            l1 = dic.get(l1)
        while l2:
            if l2 in hash_set:
                return l2
            else:
                l2 = dic.get(l2) 
        return None 
    def dfs(self,node,dic):
        if node:
            if node.left: 
                dic[node.left] = node
            if node.right: 
                dic[node.right] = node
            self.dfs(node.left,dic)
            self.dfs(node.right,dic)
```
```C++ []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map <TreeNode*, TreeNode*> hash;
        hash[root] = NULL;
        dfs(root, hash);
        set <TreeNode*> set;
        while (p){
            set.insert(p);
            p = hash[p];
        }
        while (q){
            if (set.find(q) != set.end()){
                return q;
            }
            else{
                q = hash[q];
            }
        }
        return NULL;
    }
    void dfs(TreeNode* node, map <TreeNode*, TreeNode*> &hash){
        if (node) {
            if (node->left) hash[node->left] = node;
            if (node->right) hash[node->right] = node;
            dfs(node->left, hash);
            dfs(node->right, hash);    
        }
    }
    
};
```
## 递归思路

递归时分两种情况：
1)p和q在一条分支上：最终会返回最上面的节点，即p在上返回p，q在上返回q。
2)p和q不在同一分支时会有一条分支不断向上返回p，另一条分支不断向上返回q，当左右分支都不为空时，返回该节点，即为最近公共祖先。
```python []
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if (root == None or root == p or root == q): return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if (left and right):
            return root
        elif (left and right == None):
            return left
        else:
            return right
```

```C++ []
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right){
            return root;
        }
        return left? left:right;
    }
};
```