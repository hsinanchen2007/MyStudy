### 解题思路

更新

发现一个颜色标记法更为好记，前序、中序、后序遍历可以统一用这种方法处理，只需要调整一下入栈顺序即可，附上[来源](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/)，感谢大佬！

颜色标记法的本质也是模拟递归调用入栈出栈，但是好记得多。

这个方法有两个过程：入栈和出栈，在遍历完所有节点前一直反向压栈，遍历完之后一直出栈;

这巧妙的模拟了递归调用的两个过程，调用阶段压栈，调用完回归。

注意栈先进后出， 所以压栈顺序与遍历顺序相反。

### 前序遍历 颜色标记法

```cpp
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<pair<char, TreeNode*>> s;
        char white = 1;
        char grey = 0;
        s.push(make_pair(white, root));
        while(!s.empty()) {
            char color = s.top().first;
            TreeNode* node = s.top().second;
            s.pop();
            if(node == NULL) continue;
            if(color == white) {
                //压栈顺序与遍历顺序相反
                //前序:本来是node、node->left、node->right
                s.push(make_pair(white, node->right));
                s.push(make_pair(white, node->left));
                s.push(make_pair(grey, node));
                // //中序:本来是node->left、node、node->right
                // s.push(make_pair(white, node->right));
                // s.push(make_pair(white, node->left));
                // s.push(make_pair(grey, node));
                // //后序:本来是node->left、node->right、node
                // s.push(make_pair(white, node->right));
                // s.push(make_pair(white, node->left));
                // s.push(make_pair(grey, node));

            }
            else {
                res.push_back(node->val);
            }  
        }
        return res;
    }
private:
    vector<int> res;
};
```

------------------------------------------分割线---------------------------------------------


以下为原答案

二叉树的前序（先序）遍历对于单个节点来说有点像广度优先遍历，但是整体上看其实是深度优先遍历，对于单个节点，先访问这个节点，然后访问此节点的左孩子，然后访问这个孩子的右孩子；看起来是层级遍历，也就是广度优先遍历；但是对于整棵树来说，先访问root节点，然后访问root->left， 此时，现在当前考虑的节点变为root->left，继续按照前序遍历规则，先访问当前root节点，root->left， 然后访问当前节点的左孩子，又进入下一层。所以其实是一直访问左孩子，直到某个左孩子为空，才去访问对应的右孩子。

迭代难就难在如何维护栈，栈中应该保存什么，何时保存，何时出栈。注意我们上面说的，前序遍历首先是左孩子一条道走到黑，走到尽头才去走同层的右孩子，所以我们每次进入一层，先保存当前节点值到最终需要返回的结果vector<int> res中，然后保存当前节点的右孩子，以便当前节点的左孩子为空时能继续走右孩子，所以有：

**栈保存什么： 当前节点的右孩子
何时入栈： 访问当前节点的时候
何时出栈： 左孩子走到尽头了。**

递归的话就很简单了，只需要根据前序遍历的意思写代码就行了，程序自动维护栈。

### 迭代

```cpp
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; //维护栈
        while(root != NULL || !s.empty()) {
            while(root != NULL) {//左孩子走到黑
                res.push_back(root->val);//保存当前值
                s.push(root->right);//右孩子入栈
                root = root->left;//左孩子走到黑
            }
            root = s.top();//右孩子出栈
            s.pop();
        }
        return res;
    }
private:
    vector<int> res;
};
```

### 递归

```cpp
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
    vector<int> preorderTraversal(TreeNode* root) {
        F(root);
        return res;
    }

    //前序
    void F(TreeNode* root) {
        if(root == NULL) 
            return;
        else {
            res.push_back(root->val);
            F(root->left);
            F(root->right);
        }
    }
    //后序
    void A(TreeNode* root) {
        if(root == NULL)
            return;
        A(root->left);
        A(root->right);
        res.push_back(root->val);
    }
    //中序
    void M(TreeNode* root) {
        if(root == NULL) 
            return;
        else {
            M(root->left);
            res.push_back(root->val);
            M(root->right);
        }
    }
private:
    vector<int> res;
};
```


