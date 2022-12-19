```
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //开头写  递归到最后的那些节点应该返回什么
        //然后写  递归一下，会出来的东西
        //最后写  递归出来的东西(不是最后的那些节点)应该返回什么

        if(root == nullptr || root == p || root == q) return root; 
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left == nullptr && right == nullptr)
            return nullptr;
        else if(left == nullptr && right != nullptr)
            return right;
        else if(left != nullptr && right == nullptr)
            return left;
        else
            return root;
    }

//p=0,q=8
//                 3
//         5               1
//     6       2       0       8
//           7   4     

//返回值-> 都写出来了
//                                         3->1(通过第三个条件返回的)
//            5->null(通过第二个条件返回的)                             1->1(通过最后一个条件返回的)
//
//     6->null           2->null                   0->0(通过第一个条件返回的)             8->8(通过第一个条件返回的)
//
// ->null  ->null   7->null      4->null(通过第二个条件返回的)      
//
//              ->null ->null  ->null ->null(通过第一个条件返回的) 

};
```
