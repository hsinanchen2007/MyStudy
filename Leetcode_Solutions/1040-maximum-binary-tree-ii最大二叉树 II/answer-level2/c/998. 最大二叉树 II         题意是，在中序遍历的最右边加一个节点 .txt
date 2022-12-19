### 解题思路
注意明白题意，
根据示例解释， 给出的序列是中序遍历，  附加值必须在数组最右边，即中序遍历最后一个值。

所以得出结论： 如果插入值大于root，则将root作为插入值的left；  
              如果插入值小于root， 则继续再root 的right里继续找

示例 1：



输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：A = [1,4,2,3], B = [1,4,2,3,5]



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


struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
    struct TreeNode *newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newnode->val = val;
    newnode->left = newnode->right = NULL;

    if(root == NULL || root->val < val){
        newnode->left = root;
        return newnode;
    }

    struct TreeNode *temp = root;
    //关键循环， 从右子树一直往下找待加入那一层。
    //根据后续遍历递增关系来确定哪一层待加
    while(temp->right && temp->right->val > val)
        temp = temp->right;
    
    if(temp->right == NULL){
        temp->right = newnode;
    }else{
        newnode->left = temp->right;
        temp->right = newnode;
    }
    return root;
}
```