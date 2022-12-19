
层序遍历
==============


```cpp

class Solution {
public:
    //层序遍历
    int findBottomLeftValue(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> NodeQueue;
        int res=0;
        TreeNode*current=new TreeNode(0);
        //先让根节点入队
        NodeQueue.push(root);
        //弹空队列
        while(!NodeQueue.empty()){
            //每个元素出队时，让其子节点入队
            current=NodeQueue.front();
            NodeQueue.pop();
            //保存每层数值
            res=current->val;
            //每层从右往左入队，最后一个元素即为最底层最左边的值
            if(current->right!=NULL)NodeQueue.push(current->right);
            if(current->left!=NULL)NodeQueue.push(current->left);
        }
        return res;
    }
};
```