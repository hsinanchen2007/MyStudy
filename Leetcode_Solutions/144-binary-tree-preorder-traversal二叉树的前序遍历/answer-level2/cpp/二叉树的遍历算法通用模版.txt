本题解主要是为了记录一下自己学习的心得，便于日后自己查找相关内容，如果大家需要欢迎自取，另外这里不涉及莫里斯遍历。
二叉树的遍历顺序如下：
前序遍历：根左右；中序遍历：左根右；后序遍历：左右根。
**1.迭代**
(1)通用解法：需要借助哈希表
(a)准备阶段:
由于使用深度优先搜索，第一个遍历的树节点一定是这棵树的根节点。建立一个栈，将根节点入栈，迭代循环条件为*栈非空*。
此阶段模版为：
```
vector<int> ans;
        if(root==NULL) return {};
        stack<TreeNode*> helper;
        helper.push(root);
        while(!helper.empty()){
        //遍历代码
        }
        return ans;
```
(b)遍历阶段:
经历了准备阶段后，需要明确遍历的顺序。对于后序遍历，由于顺序为左右根，因此只有当某个节点的左右孩子节点都已经遍历完成后，此节点的值才可以存入数组ans中；对于中序遍历，由于顺序为左根右，因此只有当某个节点的左孩子节点遍历完成后，此节点的值才可以存入数组ans中，之后再遍历右孩子节点；对于前序遍历，由于顺序为根左右，因此可以首先将节点的值存入数组ans中，再遍历左右孩子节点。
因此核心在于：使用一个哈希表visited，记录当前节点node的左右孩子节点的遍历结果。如果visited.count(node->left)!=0，则代表左孩子节点已经遍历了。同理，visited.count(node->right)!=0记录了右孩子节点的结果。
对于前序遍历来说，不需要哈希表，因为首先遍历的是根节点，并不需要判断其左右孩子节点是否已经遍历；对于中序遍历来说，需要哈希表记录左孩子节点是否已经遍历、右孩子节点是否已经入栈（避免重复入栈）；对于后序遍历来说，需要哈希表记录左右孩子节点是否已经遍历。因此代码如下：
*前序遍历*：
```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return {};
        stack<TreeNode*> qianxu;
        qianxu.push(root);
        while(!qianxu.empty()){
            TreeNode* temp = qianxu.top();
            qianxu.pop();
            if(temp->right!=NULL) qianxu.push(temp->right);
            if(temp->left!=NULL) qianxu.push(temp->left);
            ans.push_back(temp->val);  //不需要判断左右孩子节点是否已经遍历
        }
        return ans;
    }
};
```
*中序遍历*：
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> zhongxu;
        unordered_map<TreeNode*,int> visited;
        zhongxu.push(root);
        while(!zhongxu.empty()){
            TreeNode* current = zhongxu.top();
            zhongxu.pop();
            bool leftvisited = true;
            if(current->right!=NULL&&visited.count(current->right)==0){
                zhongxu.push(current->right);  
                visited[current->right] = 1; //避免重复入栈
            }
            if(current->left!=NULL&&visited.count(current->left)==0){
                zhongxu.push(current); //如果左孩子节点并未遍历，则需要重新把当前节点入栈
                zhongxu.push(current->left);
                visited[current->left] = 1;
                leftvisited = false;
            }
            if(leftvisited){  //只需要判断左孩子节点是否遍历过即可
                ans.push_back(current->val);
            }   
        }
        return ans;
    }
};
```
*后序遍历*：
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> houxu;
        unordered_map<TreeNode*,int> visited;
        houxu.push(root);
        while(!houxu.empty()){
            TreeNode* temp = houxu.top();
            bool leftvisited = true;
            bool rightvisited = true;
            if(temp->right!=NULL&&visited.count(temp->right)==0){
                houxu.push(temp->right);
                visited[temp->right] = 1;
                rightvisited = false;
            }
            if(temp->left!=NULL&&visited.count(temp->left)==0){
                houxu.push(temp->left);
                visited[temp->left] = 1;
                leftvisited = false;
            }
            if(leftvisited&&rightvisited){   //需要判断左右孩子节点是否均已经遍历
                ans.push_back(temp->val);
                houxu.pop();
            }
        }
        return ans;
    }
};
```
(2)非通用解法：
中序遍历、后序遍历有其特色的解法，并不需要使用哈希表。
*中序遍历*：
循环判断条件不只是栈非空，代码如下：
```
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> zhongxu;
        TreeNode* current = root;
        while(current!=NULL||!zhongxu.empty()){
            while(current!=NULL){
                zhongxu.push(current);
                current = current->left;
            }
            current = zhongxu.top();
            zhongxu.pop();
            ans.push_back(current->val);
            current = current->right;     
        }
        return ans;
    }
};
```
*后序遍历*：
特色之处在于，可把左右根的顺序变为根右左的逆序，代码如下：
```
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> houxu;
        houxu.push(root);
        while(!houxu.empty()){
            TreeNode* temp = houxu.top();
            houxu.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL){
                houxu.push(temp->left);
            }
            if(temp->right!=NULL){   //按照根右左遍历，则右比左先出栈，所以右节点后入栈
                houxu.push(temp->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
**2.递归**
递归解法较简单，按照遍历的顺序调用递归函数即可，代码如下：
*前序遍历*：
```
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};
```
*中序遍历*：
```
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};
```
*后序遍历*：
```
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};
```










