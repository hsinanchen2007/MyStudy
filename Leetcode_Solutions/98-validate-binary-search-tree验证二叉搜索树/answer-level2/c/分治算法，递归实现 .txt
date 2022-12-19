分治思想

验证某棵树是否是二叉搜索树，需要保证

左子树
- 为空
- 若不为空，则左子树也是二叉搜索树，并且左子树的最大元素值小于当前树根的值

右子树
- 为空
- 若不为空，则右子树也是二叉搜索树，并且右子树的最小元素值大于当前树根的值

所以基于这个思想，采用递归的实现方式，但是由于只能有一个返回值，还要包含
- 该子树是否是二叉搜索树
- 该子树的元素最小值
- 该子树的元素最大值
这 3 个信息，所以新定义一个结构体类型，Res，其中包含这 3 个信息

代码实现如下

```c []
typedef struct {
    bool result;
    int max;
    int min;
} Res;

Res isValidBSTRecur(struct TreeNode* root);

bool isValidBST(struct TreeNode* root){
    if (root == NULL) return true;
    Res r = isValidBSTRecur(root);
    return r.result;
}

Res isValidBSTRecur(struct TreeNode* root) {
    Res r, rl, rr;
    if (root->left != NULL) {
        rl = isValidBSTRecur(root->left);
        if (!rl.result || rl.max >= root->val) {
            r.result = false;
            return r;
        }
        r.min = rl.min;
    } 
    else {
        r.min = root->val;
    }
    if (root->right != NULL) {
        rr = isValidBSTRecur(root->right);
        if (!rr.result || rr.min <= root->val) {
            r.result = false;
            return r;
        }       
        r.max = rr.max;
    } 
    else {
        r.max = root->val;
    }
    r.result = true;
    return r;
}


```



