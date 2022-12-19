# 二叉树后序非递归

<br>

## 两种方法都基于前序改进而来

<br>

### >先看前序
```
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    if(root==nullptr)
        return v;
    stack<TreeNode*> s;
    TreeNode *cur=root;
    while(cur || !s.empty()){
        while(cur){
            v.push_back(cur->val);
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top()->right;
        s.pop();
    }
    return v;
}
```

<br>

### >这时第一种写法就是采用根右左的遍历方法，最后再将结果翻转
```
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    if(root==nullptr)
        return v;
    stack<TreeNode*> s;
    TreeNode *cur=root;
    while(cur || !s.empty()){
        while(cur){
            v.push_back(cur->val);
            s.push(cur);
            cur=cur->right;         //修改1，先遍历右子树
        }
        cur=s.top()->left;          //修改2，再遍历左子树
        s.pop();
    }
    reverse(v.begin(), v.end());
    return v;
    }
```

<br>

### >第二种写法是建立一个指向前一节点的指针，标记右孩子是否被访问
```
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    if(root==nullptr)
        return v;
    stack<TreeNode*> s;
    TreeNode *cur=root;
    TreeNode *pre=nullptr;                  //修改1，增加指向前一结点的指针
    while(cur || !s.empty()){
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        if(cur->right==nullptr || cur->right==pre){     //修改二，增加判断是否该输出结点
            v.push_back(cur->val);
            s.pop();
            pre=cur;
            cur=nullptr;
        }
        else
            cur=cur->right;
    }
    return v;
}
```

<br>

## 这个写法可以说非常简洁

<br>


