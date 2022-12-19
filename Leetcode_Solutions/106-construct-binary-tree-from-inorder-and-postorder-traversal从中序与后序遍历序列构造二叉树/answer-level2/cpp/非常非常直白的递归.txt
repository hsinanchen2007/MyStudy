费空间换智商哈哈哈

```
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if(inorder.size()==0&&postorder.size()==0) return NULL;
        
        int rootval=postorder.back();  //后序遍历最后一个元素为根节点的值
        TreeNode* root=new TreeNode(rootval);
                                                    
        if(inorder.size()==1&&postorder.size()==1) {root->left=NULL;root->right==NULL;return root; }
        //前序遍历和后序遍历仅有一个元素时，即为分支到头，左右设为NULL，直接返回当前节点即可

        vector<int>::iterator it = find(inorder.begin(), inorder.end(), rootval);
        int x=distance(inorder.begin(), it); //找到根节点在前序遍历中的下标
        
        vector<int> inleft(inorder.begin(), inorder.begin() + x);//前序遍历中根的前面为左子树的前序遍历
        vector<int> inright(inorder.begin() + x + 1, inorder.end());//根的后面是右子树的前序遍历

        vector<int> postleft(postorder.begin() , postorder.begin() + x);//后序遍历的左子树元素个数与前序遍历左子树个数相同
        vector<int> postright(postorder.begin() + x , postorder.end() - 1);//其余部分除根节点外，均为右子树的后续遍历
        
        root->left=buildTree(inleft,postleft);//左子树的前序遍历和后序遍历
        root->right=buildTree(inright,postright);//右子树的前序遍历和后序遍历
        
        return root;
    } 
```
