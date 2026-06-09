### 解题思路
一开始想到，先中序遍历，得到数组，然后重新建立一棵树。
然后又改进，在原树上改变指针关系，但没有平衡树那么难。但是有个例子超时。
然后只能看别人写的代码，改进的地方就是通过非递归的形式获取中序序列。然后在建立一棵树。感谢这位大佬。
代码见下方，后两个超时

### 代码

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
 1  非递归形式获取中序序列 ，
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        // 首先获取中序遍历序列，采用非递归方式,队列来保存序列
        queue<TreeNode*> temp;
        stack<TreeNode*> tree;
        TreeNode* node = root;
        while(!tree.empty()||node){
            if(node){  // 先不断找左子树，知道一个节点左树为空
                  tree.push(node);
                  node = node->left;
            }else{  // 此时节点左树为空，取出栈顶节点，压入queue中，在考虑右子树
                 node = tree.top();
                
                 if(node){
                     temp.push(node);
                 }
                 tree.pop();
                 node = node->right;

            }
        }
         root = temp.front();
         while(!temp.empty()){
                node = temp.front();
                temp.pop();
                node->left=NULL;
                if(!temp.empty()){
                   node->right = temp.front();
                }
             }
        return root;
   
   }
  
};
2，在原树上修改得到答案树
class Solution {
    TreeNode* cur;
public:
    TreeNode* increasingBST(TreeNode* root) {
        // 将一颗二叉排序树调整成一颗中序二叉树
        // 一共有两种思路，一种思路就是在原来树的基础上，调整成一颗中序二叉树，另一种思路，就是先产生中序遍历数组，然后再产生一颗中序树
        TreeNode* ans = new TreeNode(0);
        cur = ans;
        inorder(root);
        return ans->right;
    }
  
    
    void inorder(TreeNode* node){
        if(!node) return;
        inorder(node->left);
        cur->left=NULL;
        cur->right = node;
        cur = cur->right;
        inorder(node->right);
        return;
    }
};
3，新建立一棵树
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        // 将一颗二叉排序树调整成一颗中序二叉树
        // 一共有两种思路，一种思路就是在原来树的基础上，调整成一颗中序二叉树，另一种思路，就是先产生中序遍历数组，然后再产生一颗中序树
        if(!root) return root;
        vector<int> nums;
        inorder(root,nums);
        TreeNode* result;
        TreeNode* ans = create(result,nums);
        return ans;
    }
    TreeNode* create(TreeNode* result,vector<int> nums){
        TreeNode* root;
         for(int i=0;i<nums.size();i++){
             if(!result){
                 result = new TreeNode(nums[i]);
                 result->left = result->right = NULL;
                 root = result;

             }else{
                 result->right = new TreeNode(nums[i]);
                 result->right->left=NULL;
                 result->right->right=NULL;
                 result = result->right;
             }
         }
         return root;
    }
    void inorder(TreeNode* root,vector<int>& nums){
        if(!root) return;
        if(root->left) inorder(root->left,nums);
        nums.push_back(root->val);
        //delete root;
        if(root->right) inorder(root->right,nums);
        return;
    }
};
```