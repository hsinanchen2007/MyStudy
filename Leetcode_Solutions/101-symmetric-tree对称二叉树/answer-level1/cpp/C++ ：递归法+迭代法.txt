**方法一：递归**
树是镜像的问题可以拆分成左、右两个子树是镜像的，用到迭代：两棵树是镜像的，则对应子树也是镜像的。
```
class Solution {
	bool isMirror(TreeNode* t1, TreeNode* t2){
		if (t1 == NULL && t2 == NULL) return true;
		else if (t1 == NULL || t2 == NULL) return false;
		if (t1->val != t2->val) return false;
		bool L = isMirror(t1->left, t2->right);
		bool R = isMirror(t1->right, t2->left);
		return L&&R; 
	}
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		return isMirror(root->left, root->right);
	}
};
```
**方法二：迭代  用栈**
将对称的两个节点放在一起
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        stack<TreeNode*>s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty()){
            TreeNode* s1=s.top();
            s.pop();
            TreeNode* s2=s.top();
            s.pop();  
            if(s1==NULL && s2==NULL) continue;
            else if(s1==NULL || s2==NULL) return false;
            if(s1->val!=s2->val) return false;
            s.push(s1->left);
            s.push(s2->right);
            s.push(s1->right);
            s.push(s2->left);
        }
        return true;
    }    
};
```
