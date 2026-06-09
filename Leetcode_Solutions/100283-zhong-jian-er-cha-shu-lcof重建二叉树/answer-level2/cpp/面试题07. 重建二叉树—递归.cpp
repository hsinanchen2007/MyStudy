根据——>[题解](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/solution/mian-shi-ti-07-zhong-jian-er-cha-shu-di-gui-fa-qin/)

pre_root：前序中根节点的索引
dic:存储中序的节点值及索引
in_left:子树在中序中的左边界索引
in_right:子树在中序中的右边界索引
初始in_left=0, in_right=inorder.size() - 1

根据前序找到根节点pre_root  eg 3 9 20 15 7
找到根节点在中序中的索引i,将其分为左、右子树 eg  中：9|3|15 20 7 前：3|9|20 15 7
左子树的根节点在前序中坐标为pre_root+1，左子树的in_left，左子树的in_right=i-1
右子树的根节点在前序中坐标为pre_root+i-in_left+1(根节点+左子树长度+1)，右子树的in_left=i+1，左子树的in_right;

将分别将左、右子树当做独立子树重复上述过程。

重点：根据前序找根节点，根据中序中根节点索引划分左、右子树

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> dic;
        for(int i = 0; i < inorder.size(); i++) 
            dic[inorder[i]]=i;
        return recur(0, 0, inorder.size() - 1,dic,preorder);
    }
    TreeNode* recur(int pre_root, int in_left, int in_right,map<int,int>& dic,vector<int>& preorder) {
        if(in_left > in_right) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_root]);
        int i = dic[preorder[pre_root]];
        root->left = recur(pre_root + 1, in_left, i - 1,dic,preorder);
        root->right = recur(pre_root + i - in_left + 1, i + 1, in_right,dic,preorder);
        return root;
    }
};
```

