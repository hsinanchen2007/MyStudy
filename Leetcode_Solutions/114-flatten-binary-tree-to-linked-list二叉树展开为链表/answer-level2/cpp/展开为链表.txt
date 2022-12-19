方法一 前序遍历树，用一个vec记录值，再展开为链表。不合题意，这是只是记录一下。
```
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> sk;
        TreeNode* rt=root;
        vector<int> svec;
        sk.push(root);
        while(root||sk.size()){
            while(root){
                svec.emplace_back(root->val);
                sk.push(root->right);
                root=root->left;
            }
            root=sk.top();sk.pop();
        }
        for(int i=1;i<svec.size()/2;i++){
            rt->left=NULL;
            if(rt->right==NULL) rt->right=new TreeNode(svec[i]);
            else rt->right->val=svec[i]; 
            rt=rt->right;
        }
    }
};
```
方法二
![微信图片_20200106110112.jpg](https://pic.leetcode-cn.com/11c7752bac429ac28e76756f61fbafe7f3cc024bfe5d8658c4de42ba8b2b60dc-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200106110112.jpg)
```
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root!=NULL) { 
            if(root->left==NULL)  root=root->right;//考虑下一节点
            else{
                TreeNode* pre=root->left;
                while(pre->right!=NULL) pre=pre->right;// 找左子树最右节点
                pre->right=root->right;//将原右子树接到左子树的最右节点
                root->right=root->left;//将左子树插到右子树处
                root->left=NULL;//令左子树为空
            }
        }
    }
};
```
```
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->left!=NULL) {
            TreeNode* pre = root->left;
            while (pre->right!=NULL) pre=pre->right;
            pre->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        flatten(root->right);//考虑下一节点
        return;
    }
};
```
