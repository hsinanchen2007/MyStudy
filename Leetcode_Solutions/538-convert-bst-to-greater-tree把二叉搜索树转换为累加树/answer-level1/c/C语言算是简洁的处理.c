采用先右，后中，再左的方法。以当前节点为根的树的最左边的叶子 是 树的全部节点的总和。
执行71%，消耗100%。
```c
struct TreeNode* convertBST(struct TreeNode* root){
    calcNode(root);
}

int calcNode(struct TreeNode * node, int extend){
    int right, left;

    if(node.right!=NULL){
        right = calcNode(node.right, extend);
    } else {
        right = extend;
    }
    node.val += right;
    if(node.left!=NULL){
        left = calcNode(node.left, node.val);
    } else {
        left = node.val;
    }

    return left;
}
```

