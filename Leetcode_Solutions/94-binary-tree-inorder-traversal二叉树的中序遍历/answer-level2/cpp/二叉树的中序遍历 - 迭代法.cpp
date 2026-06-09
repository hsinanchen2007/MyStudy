### 解题思路：
- 前序遍历迭代算法
- 后序遍历迭代算法
    - 第一种方法
    - 第二种方法

- 中序遍历迭代算法

#### 前序遍历迭代算法：

[二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)

二叉树的遍历，整体上看都是好理解的。

三种遍历的迭代写法中，数前序遍历最容易理解。

递归思路：先树根，然后左子树，然后右子树。每棵子树递归。

在迭代算法中，思路演变成，每到一个节点 `A`，就应该立即访问它。

因为，每棵子树都先访问其根节点。对节点的左右子树来说，也一定是先访问根。

在 `A` 的两棵子树中，遍历完左子树后，再遍历右子树。

因此，在访问完根节点后，遍历左子树前，要将右子树压入栈。

#### 思路：
```
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的右子树入S;
        p = p的左子树;
    }
    p = S栈顶弹出;
}
```

#### 代码：
```
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->right);
                v.push_back(rt->val);
                rt=rt->left;
            }
            rt=S.top();S.pop();
        }
        return v;        
    }
```
#### 后序遍历迭代算法：
[二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)

有两种方法。第一种比第二种要容易理解，但多了个结果逆序的过程。

#### 第一种方法：
我们可以用与前序遍历相似的方法完成后序遍历。

后序遍历与前序遍历相对称。

思路： 每到一个节点 `A`，就应该立即访问它。 然后将左子树压入栈，再次遍历右子树。

遍历完整棵树后，结果序列逆序即可。

#### 思路：
```
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的左子树入S;
        p = p的右子树;
    }
    p = S栈顶弹出;
}
结果序列逆序;
```
#### 代码：
```
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt->left);
                v.push_back(rt->val);
                rt=rt->right;
            }
            rt=S.top();S.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
```
#### 第二种方法：
按照左子树-根-右子树的方式，将其转换成迭代方式。

思路：每到一个节点 `A`，因为根要最后访问，将其入栈。然后遍历左子树，遍历右子树，最后返回到 `A`。

但是出现一个问题，无法区分是从左子树返回，还是从右子树返回。

因此，给 `A` 节点附加一个标记T。在访问其右子树前，`T` 置为 `True`。之后子树返回时，当 `T` 为 `True`表示从右子树返回，否则从左子树返回。

当 `T` 为 `false` 时，表示 `A` 的左子树遍历完，还要访问右子树。

同时，当 `T` 为 `True` 时，表示 `A` 的两棵子树都遍历过了，要访问 `A` 了。并且在 `A` 访问完后，`A` 这棵子树都访问完成了。

#### 思路：
```
栈S;
p= root;
T<节点,True/False> : 节点标记;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    while(S不空 且 T[S.top] = True){
        访问S.top;
        S.top出S;
    }
    if(S不空){
        p = S.top 的右子树;
        T[S.top] = True;
    }
}
```
#### 代码：
```
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        unordered_map<TreeNode*,int> done;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            while(S.size() && done[S.top()]){
                v.push_back(S.top()->val);
                S.pop();
            }
            if(S.size()){
                rt=S.top()->right;
                done[S.top()]=1;    
            }
        }
        return v;
    }
```
#### 中序遍历迭代算法:
[二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

思路：每到一个节点 `A`，因为根的访问在中间，将 `A` 入栈。然后遍历左子树，接着访问 `A`，最后遍历右子树。

在访问完 `A` 后，`A` 就可以出栈了。因为 `A` 和其左子树都已经访问完成。

#### 思路：
```
栈S;
p= root;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    p = S.top 出栈;
    访问p;
    p = p的右子树;
}
```
#### 代码：
```
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* rt = root;
        while(rt || S.size()){
            while(rt){
                S.push(rt);
                rt=rt->left;
            }
            rt=S.top();S.pop();
            v.push_back(rt->val);
            rt=rt->right;
        }
        return v;        
    }
```