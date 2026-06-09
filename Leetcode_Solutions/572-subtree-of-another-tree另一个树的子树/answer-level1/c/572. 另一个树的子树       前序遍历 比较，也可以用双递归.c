### 解题思路
1. 这个思路不是很好
注意左右子节点 如果为空的话也要搞个标记。   
否则尽管 前序遍历一样，但树结构不一样。
见官方题解解释。


2.双递归，见精选题解

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

void recursive(struct TreeNode* root,int *res, int * index, bool left){
    if(root == NULL){
        if(left){
            res[(*index)++] = -123;
        }else{
            res[(*index)++] = -321;
        }
        return;
    }
        
    res[(*index)++] = root->val;
    recursive(root->left,res,index,true);
    recursive(root->right,res,index,false);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    int * resS = malloc(9024*sizeof(int));
    int * resT = malloc(9024*sizeof(int));

    int i,j=0,indexS=0,indexT=0;
    
    //memset(resS,0,1024*sizeof(int));
    //memset(resT,0,1024*sizeof(int));
    recursive(s,resS,&indexS,false);
    recursive(t,resT,&indexT,false);
    
    for(i=0;i<=indexS-indexT;i++){
        //printf("%d %d \n",resT[i],resS[i]);
        j=0;
        if(resS[i] == resT[j]){
            #if 1
            if(memcmp(&resS[i],resT,indexT*sizeof(int)) == 0)
                return true;
            #else
            for(j=1;j<indexT;j++){
                if(resS[i+j] != resT[j])
                    break;
            }
            if(j == indexT)
                return true;
            #endif
        }
    }
    return false;
}
```