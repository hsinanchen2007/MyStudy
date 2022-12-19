### 解题思路
此处撰写解题思路

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


int countNodes(struct TreeNode* root){
    int h = layers(root);
    int last_number = 0;//记录最后一层的数量
    struct TreeNode* current = root;

//      寻找最后一层的最后一个结点
    while(current){
        if(layers(current->left) == layers(current->right)){
//      左右子树的层数相等
            if(layers(current->left)==0){//表明当前结点为最后一个节点
                last_number+=1;
                break;
            }
            last_number += pow(2,layers(current->left)-1);
            current = current->right;
        }
        else{
            current = current->left;
        }

    }   
    return pow(2,h-1)+last_number-1; 
}

//  计算树的层数
int layers(struct TreeNode* root){
    int count = 0;
    while(root){
        count++;
        root = root->left;
    }
    return count;
}
```