**递归解法**

由题意可知，对于根节点凡是在根节点右子树的值都要比根节点val要大，根节点左边子树都要比根节点val值要少，同理类推。故我们首先可以假设两个极值也即是边界值，LONG_MAX和LONG_MIN，通过递归对它们进行不断更新，要注意的是，左右两边都必须满足二叉排序树的条件才为真。
```
bool isValid(TreeNode* root,long left,long right){
    if(!root) return true;
    else if(root->val<=left||root->val>=right) return false;
    return isValid(current->left,left,current->val)&&isValid(root->right,root->val,right);
}

bool isValidBST(struct TreeNode* root)
{

return isValid(root,LONG_MIN,LONG_MAX);

}
```

**中序遍历**

我们有一个很正常的思路就是，通过中序遍历来保存这个二叉树的值，可以发现如果为中序遍历保存这些值的话，他们为单调递增排列，那么判断是否为二叉搜索树只需要比较相邻结点即可，从这个思路我们可以得到：
```
void inOrder(struct TreeNode* root,int arr[],int *len){
    if(root != NULL){
        inOrder(root->left,arr,len);
        arr[(*len)++]=root->val;
        
        inOrder(root->right,arr,len);
    }
}
bool isValidBST(struct TreeNode* root){
    int arr[10000];
    int len=0;
    inOrder(root,arr,&len);
    for(int i=0;i<len-1;i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
    return true;
}

```
