## BST->inOrder 查看是否递增吧
```
执行用时 :16 ms, 在所有 C 提交中击败了47.48%的用户
内存消耗 :10.1 MB, 在所有 C 提交中击败了100.00%的用户
```
```c
void inOrder(struct TreeNode* root,int arr[],int *len){
    if(root != NULL){
        inOrder(root->left,arr,len);
        arr[*len]=root->val;
        (*len)++;
        inOrder(root->right,arr,len);
    }
}
bool isValidBST(struct TreeNode* root){
    int arr[10000];
    int len=0;
    inOrder(root,arr,&len);
    for(int i=0;i<len;i++){
        printf("%4d",arr[i]);
    }
    for(int i=0;i<len-1;i++){
        if(arr[i]>=arr[i+1]){
            return false;
        }
    }
    return true;
}
```