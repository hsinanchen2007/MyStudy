前序 ： **3** 9 20 15 7
中序 ： 9 **3** 15 20 7
前序遍历的第一个结果必为树的根，在没有重复数字的条件下，在中序结果中找树根的位置i。
```
        int flag = preorder[0],i=0;
        root = new TreeNode(flag);
        while(inorder[i] != flag)//i就是对应中序中根的位置
        {
            ++i;
        }
```
然后前序中0为根节点，1 -> i+1 的数字对应左子树的节点，i+1 -> end() 的数字对应右子树的节点。
然后中序中 0 -> i 的数字对应左子树的节点，i为根节点，i+1 -> end() 的数字对应右子树的节点。
递归调用本函数生成左子树和右子树得出结果。
```
vector<int> preorder_left,preorder_right,inorder_left,inorder_right ;
        inorder_left.assign(inorder.begin(),inorder.begin()+i);
        inorder_right.assign( (inorder.begin()+i+1) , inorder.end() );
        preorder_left.assign( (preorder.begin()+1) , (preorder.begin()+1+i) );
        preorder_right.assign( (preorder.begin()+1+i) , preorder.end() );
        root->left = buildTree(preorder_left,inorder_left);
        root->right = buildTree(preorder_right,inorder_right);
```

c++整体代码如下：

```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * root = nullptr;
        if(preorder.empty())
        {
            return root;
        }
        int flag = preorder[0],i=0;
        root = new TreeNode(flag);
        while(inorder[i] != flag)
        {
            ++i;
        }
        vector<int> preorder_left,preorder_right,inorder_left,inorder_right ;
        inorder_left.assign(inorder.begin(),inorder.begin()+i);
        inorder_right.assign( (inorder.begin()+i+1) , inorder.end() );
        preorder_left.assign( (preorder.begin()+1) , (preorder.begin()+1+i) );
        preorder_right.assign( (preorder.begin()+1+i) , preorder.end() );
        root->left = buildTree(preorder_left,inorder_left);
        root->right = buildTree(preorder_right,inorder_right);
        return root;
    }
};
```
