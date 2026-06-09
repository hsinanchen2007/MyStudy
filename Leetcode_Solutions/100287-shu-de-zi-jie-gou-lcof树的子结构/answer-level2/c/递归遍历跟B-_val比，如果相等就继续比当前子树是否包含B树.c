### 解题思路
递归遍历跟B->val比，如果相等就继续比当前子树是否包含B树

### 代码

```c
bool compare2Trees(struct TreeNode *a, struct TreeNode *b) {
    if (a == NULL && b == NULL) return true; 
    else if (a == NULL && b != NULL) return false; //A已经到底而B还未到底，肯定A包不住B
    else if (a != NULL && b == NULL) return true; //B已经到底，而A还未到底，表示A包含B树
    else { // a != NULL && b != NULL
        if (a->val != b->val) return false;
        else {
            return compare2Trees(a->left, b->left) && compare2Trees(a->right, b->right);
        }
    }
    return true; // useless
}
bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (A == NULL || B == NULL) return false;
    if (A->val == B->val) {
        if (compare2Trees(A, B)) return true;
    }
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
}
```