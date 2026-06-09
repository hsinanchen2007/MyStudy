执行用时 :28 ms, 在所有 c 提交中击败了29.05%的用户
内存消耗 :13 MB, 在所有 c 提交中击败了100.00%的用户

```
struct TreeNode* digui(int* in, int p, int q, int* post, int i, int j){
    if(i > j)
    {
        return NULL;
    }
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    memset(node, 0, sizeof(struct TreeNode));
    node->val = post[j];
    if(i == j)
    {
        return node;
    }
    int k;
    for(k = p;k<q;k++)
    {
        if(post[j] == in[k])
        {
            break;
        }
    }

    node->left = digui(in,p,k-1,post,i, i+k-p-1);
    node->right = digui(in,k+1,q,post,i+k-p,j-1);
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return digui(inorder, 0, inorderSize-1, postorder, 0, postorderSize-1);
}
```


