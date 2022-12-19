### 解题思路
利用前序遍历的思路，递归依次修改结点的左右指针，左子树指针设为NULL，右子树指针设为后驱结点。
### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* lastNode = NULL;// 设置一个全局变量结点，指向刚访问完的上一个结点
void flatten(struct TreeNode* root){
    struct TreeNode* rightTemp = root->right; 
    struct TreeNode* leftTemp = root->left; // 设置当前结点的左右孩子节点的备份，以免一会儿原地修改指针指向时丢失。
    if(root!=NULL)
    {   
        root->left = NULL;// 当前结点左孩子指针按照题意设置为空
        lastNode = root; //前序访问当前结点后，更新全局前驱结点为该结点
        
        if(leftTemp != NULL)
        {
            // 若当前结点的左孩子节点不为空，那么当前结点的后驱结点为左孩子结点
            root->right = leftTemp;
            // 递归对左孩子子树进行同样处理
            flatten(leftTemp);
        }

        // 在递归处理中，全局变量结点一直在刷新，左孩子树处理完后，更新为左孩子树遍历序列的最后一个结点
        lastNode->right = rightTemp; // 按照前序遍历，对最后结点的右孩子指针的后驱，应为当前结点root的右子孩子结点，故做该设置。
        
        if(rightTemp != NULL)
        {
            // 同理，若root结点右孩子树存在的话，递归做同样的变换处理。
            flatten(rightTemp);
        }
    }
}
```