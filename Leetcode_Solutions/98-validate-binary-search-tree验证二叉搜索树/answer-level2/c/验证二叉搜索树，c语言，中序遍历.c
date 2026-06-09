### 解题思路
递归如果单纯的判断左节点是否小、右节点是否大是错误的....可以用官方题解里头记录上下限的递归，整个左子树小，右子树大的方法。
中序遍历，用一个数组记录结点值，看中序遍历是否从小到大。其实可以压缩空间不用数组记录结点值。
### 代码

```c
void recursion(struct TreeNode* root,int* sign,int* a){
    if(root){
        recursion(root->left,sign,a);
        sign[(*a)++] = root->val;
        recursion(root->right,sign,a);
    }
}
bool isValidBST(struct TreeNode* root){
    int sign[9999999];
    int i=0;
    recursion(root,sign,&i);
    for(int j=1;j<i;j++){
        if(sign[j] <= sign[j-1]){
            return false;
        }
    }
    return true;
}
```
```
压缩空间版
bool recursion(struct TreeNode* root,long* a){
    if(root){
        if(recursion(root->left,a) == false){
            return false;
        }
        if(root->val <= *a){
            return false;
        }else{
            *a = root->val;
        }
        if(recursion(root->right,a) == false){
            return false;
        }
    }
    return true;
}

bool isValidBST(struct TreeNode* root){
    long pro = -2147483649;
    if(recursion(root,&pro) == false){
        return false;
    }
    return true;
}

```
