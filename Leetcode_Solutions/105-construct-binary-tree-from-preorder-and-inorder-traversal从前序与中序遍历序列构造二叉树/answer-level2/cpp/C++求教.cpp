```

```reasonml
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()<=0||inorder.size()<=0) 
             return NULL;
        return Construct(preorder, 0, preorder.size()-1, inorder, 0, preorder.size()-1); }
        TreeNode* Construct(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2){ 
             TreeNode* root = new TreeNode(preorder[start1]);
    if(start1 == end1) {
        if(start2 == end2 && preorder[0] == inorder[0]) return root;
        else return NULL;
           }
    // 在中序遍历中找到根结点的值
    int rootInorder = start2;
    while((rootInorder <= end2) &&(inorder[rootInorder]!=preorder[start1]) ){ 
             ++ rootInorder;
          }
    if((rootInorder == end2) && (inorder[rootInorder]!=preorder[start1])){ 
             return NULL; 
           }
      int leftLength = rootInorder - start2;
    int leftPreorderEnd = start1 + leftLength;
     if(leftLength != 0) {
      // 构建左子树
        root->left = Construct(preorder,start1 + 1, leftPreorderEnd, inorder,start2, rootInorder - 1); 
         }
	if(leftLength != (end1 - start1)) { 
      // 构建右子树
        root->right = Construct(preorder,leftPreorderEnd + 1, end1,inorder,rootInorder + 1, end2); 
         }
    return root;
        }
};
```
哪位大神帮忙指点一下，谢谢！
```
