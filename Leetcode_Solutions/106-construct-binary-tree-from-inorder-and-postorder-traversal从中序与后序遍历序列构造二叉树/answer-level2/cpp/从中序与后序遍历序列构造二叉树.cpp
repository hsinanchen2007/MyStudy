参照105题评论中[@bao-bao-ke-guai-liao](/u/bao-bao-ke-guai-liao)大佬的思路，写出的根据中序和后序构造二叉树的版本。

懒得打一个类似的。。。建议做了105再做106
![图片.png](https://pic.leetcode-cn.com/dac8f78787f1a62190aa3d9310de21ed2848940c138004af24bd49c0bfe325c9-%E5%9B%BE%E7%89%87.png)

本题与剑指offer面试题七类似。
```
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return post_order(0,inorder.size()-1,0,inorder.size()-1,inorder,postorder);
    }
    TreeNode* post_order(int leftin,int rightin,int leftpost,int rightpost,vector<int>& in,vector<int>& post){
        if(leftin>rightin||leftpost>rightpost) return nullptr;
        TreeNode* root=new TreeNode(post[rightpost]);
        int rootin=leftin;
        while(leftin<=rightin&&in[rootin]!=post[rightpost]) rootin++;
        int right=rightin-rootin;
        root->right=post_order(rootin+1,rightin,rightpost-right,rightpost-1,in,post);
        root->left=post_order(leftin,rootin-1,leftpost,rightpost-right-1,in,post);
            return root;
    }
};
```