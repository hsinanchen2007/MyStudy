无非是考虑后序遍历树的时候要返回一个什么样的值，这里使用了flag来标志了
父节点与子节点之间的关系，并按照flag的值返回。
```
int maxCross=0;
    int postorder(TreeNode *root,int flag){
        if(root){
            int left=postorder(root->left,0);
            int right=postorder(root->right,1);
            if(left==-1&&right==-1)return 0;
            left++;
            right++;
            maxCross=max(maxCross,max(left,right));
            return flag?left:right;

        }
        return -1;
    }
    int longestZigZag(TreeNode* root) {
        postorder(root,1);
        return maxCross;
    }
```
