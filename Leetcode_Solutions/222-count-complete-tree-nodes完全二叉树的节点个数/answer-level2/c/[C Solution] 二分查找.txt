### 解题思路

时间复杂度：O(d^2)


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


int getLayer(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    while(root != NULL){
        count++;
        root = root -> left;
    }
    return count;
}


bool exists(struct TreeNode* root , int pivot , int h){
    if(root == NULL){
        return false;
    }
    struct TreeNode* node = root;

    int l = 1 , r = pow(2,h) ,  tmpPivot = 0;
    while(l < r){
        tmpPivot = (l + r ) / 2 ;
        if(tmpPivot < pivot){
            node = node->right;
            l = tmpPivot + 1;
        }else{
            node = node->left;
            r = tmpPivot ;
        }
    }

    return node != NULL; 
}

int countNodes(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int h  = getLayer(root) - 1 , l = 1 , r = pow(2,h); 
    if(h == 0){
        return 1;
    }

    while(l <= r){
        int pivot = (l + r)/2;
        if(exists(root , pivot , h)){
            l = pivot + 1;
        }else{
            r = pivot - 1;
        }
    }
    return pow(2, h) -1 + l -1 ;   
    // 1. pow(2, h) -1，除了叶子节点，其总结点数为pow(2,{树的层树})-1 ， 根的层数算作1；
    // 2. l -1 , 是最后总会查看结点存在最右叶子的邻居右节点不在结束，l 会多加一次，需要减掉
}

```